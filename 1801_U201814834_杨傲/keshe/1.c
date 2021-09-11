#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
#define TYPESIZE sizeof(struct veg_type)
#define INFORMSIZE sizeof(struct veg_inform)
#define PLANSIZE sizeof(struct veg_plan)
void load();                       //README��
void Failure();                    //����ǰע�;��ں��б�ע���˴�ֻ�Ǻ������������ٸ���ճ��ע�͹�����
void addType();                    //������Ҫ��������У�������ע��
void save();
void changeType();
void deleteType();
void addInfo();
void changeInfo();
void deleteInfo();
void addPlan();
void changePlan();
void deletePlan();
void searchType(int);
void searchZich();
void searchFen();
void searchYear();
void searchName();
void count1Year();
void count2Years();
void countSum(int);
void countNu(char*);
char* isZich(char* s, char* t);
void printData();
int hang2 = 0;                      //��ȡ�ڶ�����������������һ�����⣩
int hang3 = 0;                      //��ȡ��������������������һ�����⣩����ֲ�ƻ����еļ��ؽ�ȥ������

typedef struct veg_type{
    char TypeCode;                  //�������
    char TypeName[8];               //��������
    struct veg_type *nexttype;      //ָ����һ���߲�����
    struct veg_inform *nextinf;     //ָ����һ���߲���Ϣ
}*PType;
struct veg_type *headv = NULL;
struct veg_type *hp1 = NULL;

typedef struct veg_inform{
    char VegName[20];               //�߲�����
    int VegCode;                    //�߲˱��
    int VegType;                    //�߲������
    char VegNutri[50];              //�߲�Ӫ���ɷ�,20������������50��
    struct veg_inform *nextinfo;    //ָ����һ���߲���Ϣ
    struct veg_plan *nextplan;      //ָ����һ����ֲ��Ϣ
}*PInfo;
struct veg_inform *headi = NULL;

typedef struct veg_plan{
    int PlanCode;					//��ֲ���
    int PlanVegCode;				//�߲˱�ţ���ǰһ���߲˱����ͬ
    int PlanArea;					//��ֲ���
    float PlanWeight;				//�ջ�����
    char PlanYear[5];				//��ֲ���
    struct veg_plan *next;          //ָ����һ����ֲ��Ϣ
}*PPlan;
struct veg_plan *headp = NULL;


//��ʾ�˵�
void showMenu0()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("1������ά��      2�����ݲ�ѯ      3������ͳ��      4�������˳�\n");
	printf("5����ʾ��ǰ��������\n");
	printf("Դ�����Ѽ��أ�Source data Loaded��\n");
	printf("��ѡ��ִ�еĹ��ܣ�������1~5��\n");
}


//��ʾ�˵�
void showMenu1()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("1���߲�������Ϣά��  2���߲˻�����Ϣά��  3���߲���ֲ��Ϣά��\n");
	printf("��ѡ��Ҫά���Ĺ��ܣ���1~3)\n");
	printf("����4������\n");
}


//��ʾ�˵�
void showMenu1_1()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("1�������ڵ�        2���޸Ľڵ�        3��ɾ���ڵ�      4������\n");
	printf("��ѡ��Ҫִ�еĹ��ܣ���1~4)\n");
}


//��ʾ�˵�
void showMenu1_2()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("1�������ڵ�        2���޸Ľڵ�        3��ɾ���ڵ�      4������\n");
	printf("��ѡ��Ҫִ�еĹ��ܣ���1~4)\n");
}


//��ʾ�˵�
void showMenu1_3()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("1�������ڵ�        2���޸Ľڵ�        3��ɾ���ڵ�      4������\n");
	printf("��ѡ��Ҫִ�еĹ��ܣ���1~4)\n");
}


//��ʾ�˵�
void showMenu2()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("1���߲�������Ϣ��ѯ  2���߲˻�����Ϣ��ѯ  3���߲���ֲ��Ϣ��ѯ\n");
	printf("��ѡ��Ҫ��ѯ�Ĺ��ܣ���1~3)\n");
	printf("����4������\n");
}


//��ʾ�˵�
void showMenu2_1()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("��������Ҫ��ѯ���߲˵ķ����ţ�int��\n");
	printf("����0����\n");
}


//��ʾ�˵�
void showMenu2_2()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("��������Ҫ��ѯ�ķ�ʽ��int��\n");
	printf("1���߲������Ӵ�����             2�������뼰Ӫ���ɷֲ���\n");
	printf("����0����\n");
}


//��ʾ�˵�
void showMenu2_3()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("��������Ҫ��ѯ�ķ�ʽ��int��\n");
	printf("1�������Ӵ�����ݲ���             2���߲����Ʋ���\n");
	printf("����0����\n");
}


//��ʾ�˵�
void showMenu3()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("1��ĳ��ͳ��  2����ֹ���ͳ��  3��ĳ����������  4��Ӫ���ɷ�ͳ��\n");
	printf("��ѡ��Ҫͳ�ƵĹ��ܣ���1~3)\n");
	printf("����5������\n");
}


//��ʾ�˵�
void showMenu3_1()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("��������Ҫ��ѯ����ݣ�char[5]��\n");                            //�Զ�����
}


//��ʾ�˵�
void showMenu3_2()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("��������Ҫ��ѯ����ֹ��ݣ�char[5] char[5]��\n");                 //�Զ�����
}


//��ʾ�˵�
void showMenu3_3()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("��������Ҫ��ѯ���߲˵ķ����ţ�int��\n");
	printf("����0����\n");
}


//��ʾ�˵�
void showMenu3_4()
{
	system("cls");
	printf("---------------------��ũ��ֲ��Ϣ����ϵͳ---------------------\n");
	printf("��������Ҫ��ѯ���߲˵�Ӫ���ɷ��Ӵ���char[20]��\n");              //�Զ�����
}

//������
int main()
{
	int opt = 0;
	int opt2 = 0;
	int opt3 = 0;
	PType p=NULL;
	system("color 0d");
	showMenu0();
	load();
	p = headv->nexttype;
	scanf("%d", &opt);
	getchar();
	while (opt != 4)
	{
		if (opt == 1)
		{
			showMenu1();
			scanf("%d", &opt2);
			getchar();
			while (opt2 != 4)
			{
				if (opt2 == 1)
				{
					showMenu1_1();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 4)
					{

						if (opt3 == 1)
						{
							addType();
							printData();                //Ϊ�˱��ڼ�飬�ڹ���ִ�н�����������Ϣ���һ�飬���Խ��˾�ֱ��ע�͵�����Ӱ��ʵ�ʹ���
						}
						else if (opt3 == 2)
						{
							changeType();
							printData();                //Ϊ�˱��ڼ�飬�ڹ���ִ�н�����������Ϣ���һ�飬���Խ��˾�ֱ��ע�͵�����Ӱ��ʵ�ʹ���
						}
						else if (opt3 == 3)
						{
							deleteType();
							printData();                //Ϊ�˱��ڼ�飬�ڹ���ִ�н�����������Ϣ���һ�飬���Խ��˾�ֱ��ע�͵�����Ӱ��ʵ�ʹ���
						}
						showMenu1_1();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 2)
				{
					showMenu1_2();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 4)
					{

						if (opt3 == 1)
						{
							addInfo();
							printData();                //Ϊ�˱��ڼ�飬�ڹ���ִ�н�����������Ϣ���һ�飬���Խ��˾�ֱ��ע�͵�����Ӱ��ʵ�ʹ���
						}
						else if (opt3 == 2)
						{
							changeInfo();
							printData();                //Ϊ�˱��ڼ�飬�ڹ���ִ�н�����������Ϣ���һ�飬���Խ��˾�ֱ��ע�͵�����Ӱ��ʵ�ʹ���
						}
						else if (opt3 == 3)
						{
							deleteInfo();
							printData();                //Ϊ�˱��ڼ�飬�ڹ���ִ�н�����������Ϣ���һ�飬���Խ��˾�ֱ��ע�͵�����Ӱ��ʵ�ʹ���
						}
						showMenu1_2();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 3)
				{
					showMenu1_3();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 4)
					{

						if (opt3 == 1)
						{
							addPlan();
							printData();                //Ϊ�˱��ڼ�飬�ڹ���ִ�н�����������Ϣ���һ�飬���Խ��˾�ֱ��ע�͵�����Ӱ��ʵ�ʹ���
						}
						else if (opt3 == 2)
						{
							changePlan();
							printData();                //Ϊ�˱��ڼ�飬�ڹ���ִ�н�����������Ϣ���һ�飬���Խ��˾�ֱ��ע�͵�����Ӱ��ʵ�ʹ���
						}
						else if (opt3 == 3)
						{
							deletePlan();
							printData();                //Ϊ�˱��ڼ�飬�ڹ���ִ�н�����������Ϣ���һ�飬���Խ��˾�ֱ��ע�͵�����Ӱ��ʵ�ʹ���
						}
						showMenu1_3();
						scanf("%d", &opt3);
						getchar();
					}
				}
				showMenu1();
				scanf("%d", &opt2);
				getchar();
			}
		}
		else if (opt == 2)
		{
			showMenu2();
			scanf("%d", &opt2);
			getchar();
			while (opt2 != 4)
			{

				if (opt2 == 1)
				{
					showMenu2_1();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 0)
					{
						searchType(opt3);
						showMenu2_1();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 2)
				{
					showMenu2_2();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 0)
					{
						if (opt3 == 1)
						{
							searchZich();
						}
						else if (opt3 == 2)
						{
							searchFen();
						}
						showMenu2_2();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 3)
				{
					showMenu2_3();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 0)
					{
						if (opt3 == 1)
						{
							searchYear();
						}
						else if (opt3 == 2)
						{
							searchName();
						}
						showMenu2_3();
						scanf("%d", &opt3);
						getchar();
					}
				}
				showMenu2();
				scanf("%d", &opt2);
				getchar();
			}
		}
		else if (opt == 3)
		{
			showMenu3();
			scanf("%d", &opt2);
			getchar();
			while (opt2 != 5)
			{

				if (opt2 == 1)
				{
					showMenu3_1();
					count1Year();
				}
				else if (opt2 == 2)
				{
					showMenu3_2();
					count2Years();
				}
				else if (opt2 == 3)
				{
					showMenu3_3();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 0)
					{
						countSum(opt3);
						showMenu3_3();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 4)
				{
					showMenu3_4();
					char tempNu[20];
					scanf("%s", tempNu);
					getchar();
					countNu(tempNu);
				}
				showMenu3();
				scanf("%d", &opt2);
				getchar();
			}
		}
		else if (opt == 5)
		{
			printData();
		}
		showMenu0();
		scanf("%d", &opt);
		getchar();
	}

	printf("��Ϣ�ѱ��沢��������ӭ���´�ʹ�ã�\n");
	printf("Information Saved!  Welcome Next Time!\n");
	save();                                                 //���沢��������������������������������һ����ǰ��searchName�ڲ���ĳ�߲������Զ���������һ����ǰ��count1Year������ͳ��ĳ����Զ�����
	
}

//������Ϣ
void load()
{
	//��������ڵ�Ĺ���Ͷ�ȡ���ݲ�����
    PType p,p1;
    FILE *fp;
    if( (fp = fopen("�߲�����.csv", "ab+")) == NULL)     //���ؽ�ȥ�߲�������Ϣ
        Failure();
    fseek(fp, 20L, SEEK_SET);                           //����csv�е�һ�б�����
    char delims[] = ",";
    char *line,*record;
    char buffer[1024];
    p = (PType)malloc(TYPESIZE);
    headv = p;
    p1 = (PType)malloc(TYPESIZE);
    p->nexttype = p1;
    p = p1;
    int i=1, j=1;
    int hang = 0,lie=1;                                     
    while(( line = fgets(buffer, sizeof(buffer), fp))!=NULL)//��ȡ����(����һ������)
    {
        hang++;
    }
    fseek(fp, 20L, SEEK_SET);                            //���¸�λ��������һ�к��λ��
    /*while((*/ line = fgets(buffer, sizeof(buffer), fp); /*)!=NULL)*/
    //{                                                  //����һ�е�����
    record = strtok(line, ",");                          //ȡ���Σ���һ���ǵ�һ����ȥ����
    record = strtok(NULL, ",");                          //ȡ���Σ��ڶ����ǵڶ��п�ʼ��
    while (record != NULL)                               
    {
        sprintf(p->TypeName,"%s", record);               //����������Ϣͨ��sprintf�����ڵ�
        p->TypeCode = j;
        int l = 0;
        for (l = 0; l < 8;l++)                           //ͨ����ѭ����TypeName�п��ܺ��еĻس�����ɾȥ
        {
            if((p->TypeName[l]=='\r')||(p->TypeName[l]=='\n'))
                p->TypeName[l] = '\0';
        }
        //fscanf(fp, "%s", &(p->TypeName));
        p1 = (PType)malloc(TYPESIZE);
        p->nexttype = p1;
        p = p1;
        // if (j == lie)                                      //�����õĵ�һ�п�ʼ��ȡ����
        //     break;
        j++;
        record = strtok(NULL, ",");
    }
    p->nexttype = NULL;
    lie = j;                                                  //��ȡ����������һ��֮�⣩���߲�������
    j = 1;
    //}
    fclose(fp);
    fp = NULL;
    p = headv->nexttype;
	while (p != NULL)
	{
		p->nextinf = NULL;
		p = p->nexttype;
	}




	//������Ϣ�ڵ�Ĺ���Ͷ�ȡ���ݲ�����
	PInfo p2, p3;
    i = 1;
    j = 1;
	
    int temp;
    int k = 1;                                          //i��j��k��temp��Ϊ������
    int TempCode = 0;
    char TempName[20];
    FILE *fp2;
    if( (fp2 = fopen("�߲���Ϣ.csv", "ab+")) == NULL)    //���ؽ�ȥ�߲�������Ϣ
        Failure();
    fseek(fp2, 35L, SEEK_SET);                           //����csv�е�һ�б�����
    //char delims[] = ",";
    char *line2,*record2;
    char buffer2[1024];

	while ((line2 = fgets(buffer2, sizeof(buffer2), fp2)) != NULL)//��ȡ����(����һ������)���߲˸���
	{
		hang2++;
	}
	fseek(fp2, 35L, SEEK_SET);

    while(( line2 = fgets(buffer2, sizeof(buffer2), fp2))!=NULL)
    {         
		p2 = (PInfo)malloc(INFORMSIZE);
		p2->nextinfo = NULL;
		p2->nextplan = NULL;
        record2 = strtok(line2, ",");                        //��һ���ǵ�һ��
        while (record2 != NULL)                               
        {
            if(j==1)
            {
                //TempCode = (*record2) - '0';                 //�ݴ���Ϣ���Ժ�ֵ
				sscanf(record2, "%d", &TempCode);
                record2 = strtok(NULL, ",");
                j++;
                continue;
            }
            if(j==2)
            {
                sprintf(TempName,"%s", record2);             //�ݴ���Ϣ���Ժ�ֵ
                record2 = strtok(NULL, ",");
                j++;
                continue;
            }
            if(j==3)
            {
				
                //temp = (*record2) - '0';                  //�ݴ���Ϣ���Ժ�ֵ,������书����sscanf�滻
				sscanf(record2, "%d", &temp);
				p = headv->nexttype;
                for (k = 1; k < temp;k++)
                {
                    p = p->nexttype;                        //�ҵ���Ӧ���߲�������������߲���Ϣ
                }
				if ((p->nextinf) == NULL)
				{
					p->nextinf = p2;
					headi = p2;
				}
				p2 = p->nextinf;
                while((p2->nextinfo)!=NULL)
                {
                    p2 = p2->nextinfo;
                }
                p2->VegCode = TempCode;                          //��ֵ
                sprintf(p2->VegName,"%s", TempName);
                p2->VegType = temp;
                record2 = strtok(NULL, ",");
                j++;
                continue;
            }
            if(j==4)
            {
                sprintf(p2->VegNutri,"%s", record2);
                int l = 0;
                for (l = 0; l < 50;l++)                           //ͨ����ѭ����VegNutri�п��ܺ��еĻس�����ɾȥ
                {
                    if((p2->VegNutri[l]=='\r')||(p2->VegNutri[l]=='\n'))
                        p2->VegNutri[l] = '\0';
                }
                break;
            }
            
        }
		p3 = (PInfo)malloc(INFORMSIZE);
		p2->nextinfo = p3;
		p2 = p3;
		p2->nextinfo = NULL;
		p2->nextplan = NULL;
		j = 1;
    }
    fclose(fp2);
    fp2 = NULL;
    /*p2->nextinfo = NULL;*/
    p = headv->nexttype;






	//���мƻ��ڵ�Ĺ���Ͷ�ȡ���ݲ�����
	PPlan p4, p5;
	i = 1; j = 1; k = 1;
	float tempw = 0;                                     //������ʱ��¼����
	FILE* fp3;
	if ((fp3 = fopen("��ֲ��Ϣ.csv", "ab+")) == NULL)    //���ؽ�ȥ�߲�������Ϣ
		Failure();
	fseek(fp3, 42L, SEEK_SET);                           //����csv�е�һ�б�����
	char* line3, * record3;
	char buffer3[1024];

	while ((line3 = fgets(buffer3, sizeof(buffer3), fp3)) != NULL)//��ȡ����(����һ������)���߲˸���
	{
		hang3++;
	}
	fseek(fp3, 42L, SEEK_SET);

	while ((line3 = fgets(buffer3, sizeof(buffer3), fp3)) != NULL)
	{
		p4 = (PPlan)malloc(PLANSIZE);
		p4->next = NULL;
		record3 = strtok(line3, ",");                         //��һ���ǵ�һ��
		while (record3 != NULL)
		{
			if (j == 1)
			{
				//TempCode = (*record3) - '0';                //�ݴ���Ϣ���Ժ�ֵ
				sscanf(record3, "%d", &TempCode);
				record3 = strtok(NULL, ",");
				j++;
				continue;
			}
			if (j == 2)
			{
				int sum = 0;
				int flag = 0;							      //����¼δ�ҵ�
				//temp = (*record3) - '0';                    //�ݴ���Ϣ���Ժ�ֵ
				sscanf(record3, "%d", &temp);
				p = headv->nexttype;
				PInfo pt;
				pt = p->nextinf;
				for (k = 1; k <= lie; k++)
				{
					//PInfo pt;
					pt = p->nextinf;
					while (pt != NULL)
					{
						pt = pt->nextinfo;
						sum++;
					}
					pt = p->nextinf;
					for (i = 1; i < sum; i++)				//�����ȡ���һ��Ϊ�յĽڵ�
					{
						if (pt->VegCode == temp)
						{
							flag = 1;						//����¼�ҵ���
							break;
						}
						else
						{
							pt = pt->nextinfo;
						}
					}
					if (flag == 1)
					{
						break;
					}
					else
					{
						sum = 0;
						p = p->nexttype;
					}
				}
				if (flag == 0)
				{
					printf("�߲˱��Ϊ%d���߲���Ϣδ�ҵ���\n",temp);        //���ڵ�Ҫ����ĳ�߲˱�ŵ��߲˵���ϵͳδ¼������߲˱��ʱ
					record3 = strtok(NULL, ",");
					j++;
					continue;
				}
				else
				{
					if (pt->nextplan == NULL)
					{
						pt->nextplan = p4;
						headp = p4;
					}
					p4 = pt->nextplan;
					while ((p4->next) != NULL)
					{
						p4 = p4->next;
					}
					p4->PlanCode = TempCode;
					p4->PlanVegCode = temp;
					record3 = strtok(NULL, ",");
					j++;
					continue;
				}
			}
			if (j == 3)
			{
				//TempCode = (*record3) - '0';                 //�ݴ���Ϣ���Ժ�ֵ
				sscanf(record3, "%d", &TempCode);
				p4->PlanArea = TempCode;
				record3 = strtok(NULL, ",");
				j++;
				continue;
			}
			if (j == 4)
			{
				sscanf(record3, "%f", &tempw);
				p4->PlanWeight = tempw;
				record3 = strtok(NULL, ",");
				j++;
				continue;
			}
			if (j == 5)
			{
				sprintf(p4->PlanYear, "%s", record3);
				int l = 0;
				for (l = 0; l < 5; l++)                           //ͨ����ѭ����OlanYear�п��ܺ��еĻس�����ɾȥ
				{
					if ((p4->PlanYear[l] == '\r') || (p4->PlanYear[l] == '\n'))
						p4->PlanYear[l] = '\0';
				}
				break;
			}
		}
		j = 1;
		p5 = (PPlan)malloc(PLANSIZE);
		p4->next = p5;
		p4 = p5;
		p4->next = NULL;
	}
	fclose(fp3);
	fp3 = NULL;
	/*p4->next = NULL;*/
	p = headv->nexttype;

}



//�����ڴ��ļ�ʱû�ܹ��ɹ�fopenʱ����Ҳ������������malloc�Ƿ�ɹ����ж�������д����ʱû��������
void Failure()
{
    printf("����ʧ�ܣ����ڴ���\n");
    system("pause");
    return 0;
}


//ʵ���������࣬��ڳ��ڲ����ޡ�
void addType()
{
	PType p;
	PType p1;
	int i = 1;
	char tempName[8];
	p1 = headv->nexttype;					  //p1ָ��ǰ�ڵ㣬pָ������һ���ڵ�
	p = p1->nexttype;
	while (p != NULL)						  //���p1��ָ�����һ���ڵ��ʱp==NULL����Ϊ���ݽṹ�Ĺ��쵼��ÿ�ν�β��һ���ڵ㲢ָ��
	{
		p1 = p1->nexttype;                    //p1�ӵ�һ������������
		p = p->nexttype;
		i++;
	}
	printf("��������Ҫ���ӵ��������ƣ�char[8])\n");
	scanf("%s", tempName);
	getchar();
	sprintf(p1->TypeName, "%s", tempName);    //��p1�ڵ㸳ֵ
	p1->TypeCode = i;
	p1->nextinf = NULL;
	p = (PType)malloc(TYPESIZE);              //�����½����ں��棬���ֽṹ
	p->nexttype = NULL;
	p->nextinf = NULL;
	p1->nexttype = p;
	printf("�������ɹ�!Add Type Successfully!\n");
	system("pause");
	
	
}


//ʵ�ָı����࣬��ڳ��ڲ����ޡ�
void changeType()
{
	PType p;
	PType p1;
	int i = 1;
	char tempName[8];
	int temp;
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("��ѡ����������Ҫ�ı���߲���������������\n");
	printf("1���߲�����              2��������\n");
	scanf("%d", &i);                                             //���ֹ���ѡ��һ�ֽ�������
	if (i == 1)
	{
		scanf("%s", tempName);
		getchar();
		while (strcmp(p1->TypeName, tempName) != 0)              //�ж��Ƿ��ҵ�
		{
			p1 = p1->nexttype;
			p = p->nexttype;
		}
	}
	else if (i == 2)
	{
		scanf("%d", &temp);
		getchar();
		while (p1->TypeCode != temp)                              //�ж��Ƿ��ҵ�
		{
			p1 = p1->nexttype;
			p = p->nexttype;
		}
	}
	printf("����������Ҫ�����ı��Ϊ���߲�����(char[8])\n");     //�߲˱�Ų�������ģ����Ǹ���Ҫ�ı�öණ���������޸Ĵ˴�����������
	scanf("%s", tempName);
	getchar();
	sprintf(p1->TypeName, "%s", tempName);                       //����Ϣͨ��sprintf�����ڵ�
	int l = 0;
	for (l = 0; l < 8; l++)                                      //ͨ����ѭ����TypeName�п��ܺ��еĻس�����ɾȥ
	{
		if ((p->TypeName[l] == '\r') || (p->TypeName[l] == '\n'))
			p->TypeName[l] = '\0';
	}
	printf("�޸���ɣ�Successfully Changed��\n");
	system("pause");

}


//ʵ��ɾ�����࣬��ڳ��ڲ����ޡ�
void deleteType()
{
	PType p;
	PType p1;
	PType pb;                                                    //p1ָ��ǰ�ڵ㣬pָ����һ����pbָ��ǰһ��
	int i = 1;
	char tempName[8];
	int temp;
	pb = headv;
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("��ѡ����������Ҫɾ�����߲���������������\n");
	printf("1���߲�����              2��������\n");            //��ѡһ��������
	scanf("%d", &i);
	if (i == 1)
	{
		scanf("%s", tempName);
		getchar();
		while (strcmp(p1->TypeName, tempName) != 0)              //�ж��Ƿ��ҵ�
		{
			pb = pb->nexttype;
			p1 = p1->nexttype;
			p = p->nexttype;
		}
		pb->nexttype = p;
		p1->nexttype = NULL;
	}
	else if (i == 2)
	{
		scanf("%d", &temp);
		getchar();
		while (p1->TypeCode != temp)                             //�ж��Ƿ��ҵ�
		{
			pb = pb->nexttype;
			p1 = p1->nexttype;
			p = p->nexttype;
		}
		pb->nexttype = p;
		p1->nexttype = NULL;
	}
	printf("ɾ����ɣ�Successfully Deleted��\n");
	system("pause");

}



//ʵ��������Ϣ����ڳ��ڲ����ޡ�
void addInfo()
{
	PType p;
	PType p1;
	int i = 1;
	char tempName[8];
	char tempNu[50];
	int temp=0;
	p1 = headv->nexttype;
	p = p1->nexttype;
	PInfo p3=NULL, p4=NULL;
	printf("��������Ҫ���ӵ���Ϣ���������루int)\n");
	scanf("%d", &temp);
	getchar();
	printf("��������Ҫ���ӵ���Ϣ���߲����ƣ�char[8])\n");
	scanf("%s", tempName);
	getchar();
	printf("��������Ҫ���ӵ���Ϣ��Ӫ���ɷ֣�char[50])\n");
	scanf("%s", tempNu);
	getchar();
	while (p1->TypeCode != temp)               //�ж��Ƿ��ҵ�
	{
		p1 = p1->nexttype;
		p = p->nexttype;
	}
	p3 = p1->nextinf;
	if (p3 == NULL)                            //���ж����е��������ֻ��һ����ȴ��ɾ��֮���޲˻��Ǳ�����޲˵����
	{										   //��ʱ��Ҫ�½��ڵ���ں���
		p4 = (PInfo)malloc(INFORMSIZE);
		p4->nextinfo = NULL;
		p4->nextplan = NULL;
		p3 = p4;
		p1->nextinf = p3;
	}
	p4 = p3->nextinfo;
	while (p4 != NULL)						  //���p4ָ�����һ���ڵ㣬���ڹ�������ÿ�ν�β��һ���ڵ㲢ָ��
	{
		p4 = p4->nextinfo;
		p3 = p3->nextinfo;
	}
	p3->VegType = p1->TypeCode;               //��ڵ㸳ֵ
	p3->VegCode = ++hang2;
	sprintf(p3->VegName, "%s", tempName);
	sprintf(p3->VegNutri, "%s", tempNu);
	p3->nextinfo = NULL;
	p3->nextplan = NULL;
	p4 = (PInfo)malloc(INFORMSIZE);          //�����½���ں��汣�ֽṹ
	p4->nextinfo = NULL;
	p4->nextplan = NULL;
	p3->nextinfo = p4;
	printf("�����Ϣ�ɹ�!Add Information Successfully!\n");
	system("pause");

}



//ʵ���޸���Ϣ����ڳ��ڲ����ޡ�
void changeInfo()
{
	PType p;
	PType p1;
	int i = 1;
	char tempName[8];
	char tempNu[50];
	int temp;
	p1 = headv->nexttype;
	p = p1->nexttype;
	PInfo p3 = NULL, p4 = NULL;
	printf("��ѡ����������Ҫ�ı���߲���Ϣ�е��߲˱�Ż���������\n");
	printf("1���߲�����              2���߲˱��\n");
	scanf("%d", &i);
	if (i == 1)
	{
		scanf("%s", tempName);
		getchar();
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
		
		while (strcmp(p3->VegName, tempName) != 0)              //�ж��Ƿ��ҵ�
		{
			p3 = p3->nextinfo;
			p4 = p4->nextinfo;
			if (p4 == NULL)                                    //����Ϣ�����꣬����һ�������Ӧ����Ϣ��
			{
				p1 = p1->nexttype;
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
			}
		}
	}
	else if (i == 2)
	{
		scanf("%d", &temp);
		getchar();
		p3 = p1->nextinf;
		p4 = p3->nextinfo;

		while (p3->VegCode!=temp)                               //�ж��Ƿ��ҵ�
		{
			p3 = p3->nextinfo;
			p4 = p4->nextinfo;
			if (p4 == NULL)                                     //����Ϣ�����꣬����һ�������Ӧ����Ϣ��
			{
				p1 = p1->nexttype;
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
			}
		}
	}
	printf("��������Ҫ�ĳɵ��߲����ƣ�char[8])\n");
	scanf("%s", tempName);
	getchar();
	printf("��������Ҫ�ĳɵ�Ӫ���ɷ֣�char[50])\n");
	scanf("%s", tempNu);
	getchar();
	sprintf(p3->VegName, "%s", tempName);
	sprintf(p3->VegNutri, "%s", tempNu);
	printf("�޸���ɣ�Successfully Changed��\n");
	system("pause");
}



//ʵ���޸���Ϣ����ڳ��ڲ����ޡ�
void deleteInfo()
{
	PType p;
	PType p1;
	PType ptemp;
	int i = 1;
	char tempName[8];
	int temp;
	p1 = headv->nexttype;
	p = p1->nexttype;
	PInfo p3 = NULL, p4 = NULL, pb = NULL;
	printf("��ѡ����������Ҫɾ�����߲���Ϣ�е��߲˱�Ż���������\n");
	printf("1���߲�����              2���߲˱��\n");
	scanf("%d", &i);
	if (i == 1)
	{
		scanf("%s", tempName);
		getchar();
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
		while (strcmp(p3->VegName, tempName) != 0)                        //�ж��Ƿ��ҵ�
		{
			pb = p3;
			p3 = p3->nextinfo;
			p4 = p4->nextinfo;
			if (p4 == NULL)                                              //����Ϣ�����꣬����һ�������Ӧ����Ϣ��
			{
				p1 = p1->nexttype;
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
				pb = NULL;                                                 //��pb����ָ����ָ��p3ǰһ���ڵ㣬��Ϊ�գ���pbӦ��ΪPType�ڵ㣬��Ҫ����һ����Ϣ�ڵ�ɾȥ
			}
		}
	}
	else if (i == 2)
	{
		scanf("%d", &temp);
		getchar();
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
		while (p3->VegCode != temp)                                        //�ж��Ƿ��ҵ�
		{
			pb = p3;
			p3 = p3->nextinfo;
			p4 = p4->nextinfo;
			if (p4 == NULL)                                                 //����Ϣ�����꣬����һ�������Ӧ����Ϣ��
			{
				p1 = p1->nexttype;
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
				pb = NULL;
			}
		}
	}
	if (pb == NULL)                                                          //pb==NULL�������ζ�Ŵ�ʱp3��Ϣ�ڵ�Ϊ����ڵ����ĵ�һ������ڵ㣬��pb��ʱ����p3��ǰһ����Ϣ�ڵ��������ڵ�
	{
		ptemp = headv->nexttype;
		while (ptemp->nextinf != p3)
		{
			ptemp = ptemp->nexttype;
		}
		ptemp->nextinf = p4;
		p3->nextinfo = NULL;
	}
	else                                                                     //��Ϊ�ռ��ҵ�����Ϣ���е�p3�Լ���ǰ��ڵ�
	{
		pb->nextinfo = p4;
		p3->nextinfo = NULL;
	}
	printf("ɾ����ɣ�Successfully Deleted��\n");
	hang3--;
	system("pause");
}



//ʵ�����Ӽƻ�����ڳ��ڲ����ޡ�
void addPlan()
{
	PType p;
	PType p1;
	int i = 1;
	int temp;
	int temparea;
	float tempw;
	char tempYear[5];
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("��������Ҫ�������߲������µ���ֲ��Ϣ���߲˱��int��\n");
	scanf("%d", &temp);
	getchar();
	printf("��������������ֲ��Ϣ�е���ֲ�����int)\n");
	scanf("%d", &temparea);
	getchar();
	printf("��������������ֲ��Ϣ�е��ջ�������float)\n");
	scanf("%f", &tempw);
	getchar();
	printf("��������������ֲ��Ϣ�е���ֲ���(char[5])\n");                     //Ĭ�������ļƻ���ݺ��Ѵ��ڵ���ݾ���ͬ����ͬ����ֲ��Ϣ���߲˱�ź���ݽ�������
	scanf("%s", tempYear);
	getchar();
	PInfo p3 = NULL, p4 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	while (p3->VegCode != temp)												  //�ж��Ƿ��ҵ�
	{
		p3 = p3->nextinfo;
		p4 = p4->nextinfo;
		if (p4 == NULL)                                                    //����Ϣ�����꣬����һ�������Ӧ����Ϣ��
		{
			p1 = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
		}
	}
	PPlan p5, p6;
	p5 = p3->nextplan;
	if (p5 == NULL)                                                           //����ɵ��������ֻ��һ����ȴ��ɾ��֮���޲˵����
	{
		p6 = (PPlan)malloc(PLANSIZE);                                         //��ʵ�ֵ�ǰ�߲˽ڵ���û����ֲ�ƻ�ʱ���޵��е����plan
		p6->next = NULL;
		p5 = p6;
		p3->nextplan = p5;
	}
	p6 = p5->next;
	while (p6 != NULL)
	{
		p5 = p5->next;
		p6 = p6->next;
	}
	p5->PlanCode = ++hang3;														//��ڵ㸳ֵ
	p5->PlanVegCode = temp;
	p5->PlanArea = temparea;
	p5->PlanWeight = tempw;
	sprintf(p5->PlanYear, "%s", tempYear);
	p5->next=NULL;
	p6 = (PPlan)malloc(PLANSIZE);
	p6->next = NULL;
	p5->next = p6;
	printf("��Ӽƻ��ɹ�!Add Plan Successfully!\n");
	system("pause");

}



//ʵ���޸ļƻ�����ڳ��ڲ����ޡ�
void changePlan()
{
	PType p;
	PType p1;
	int i = 1;
	int temp;
	int temparea;
	float tempw;
	char tempYear[5];
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("��������Ҫ�ı������߲˵���ֲ��Ϣ���߲˱��int��\n");
	scanf("%d", &temp);
	getchar();
	printf("��������Ҫ�ı������߲���һ�����ֲ��Ϣ����ֲ���char[5]��\n");
	scanf("%s", tempYear);
	getchar();
	PInfo p3 = NULL, p4 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	while (p3->VegCode != temp)                                               //�ж��Ƿ��ҵ�
	{
		p3 = p3->nextinfo;
		p4 = p4->nextinfo;
		if (p4 == NULL)                                                      //����Ϣ�����꣬����һ�������Ӧ����Ϣ��
		{
			p1 = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
		}
	}
	PPlan p5, p6;
	p5 = p3->nextplan;
	p6 = p5->next;
	while (strcmp(p5->PlanYear,tempYear)!=0)                                   //�ж��Ƿ��ҵ�
	{
		p5 = p5->next;
		p6 = p6->next;
	}
	printf("������ĳɵ���ֲ�����int)\n");
	scanf("%d", &temparea);
	getchar();
	printf("������ĳɵ��ջ�������float)\n");
	scanf("%f", &tempw);
	getchar();
	printf("������ĳɵ���ֲ���(char[5])\n");
	scanf("%s", tempYear);
	getchar();
	p5->PlanVegCode = temp;														//��ڵ㸳ֵ
	p5->PlanArea = temparea;
	p5->PlanWeight = tempw;
	sprintf(p5->PlanYear, "%s", tempYear);
	printf("�޸���ɣ�Successfully Changed��\n");
	system("pause");
}




//ʵ��ɾ���ƻ�����ڳ��ڲ����ޡ�
void deletePlan()
{
	PType p;
	PType p1;
	int i = 1;
	int temp;
	int temparea;
	float tempw;
	char tempYear[5];
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("��������Ҫɾ�������߲˵���ֲ��Ϣ���߲˱��int��\n");
	scanf("%d", &temp);
	getchar();
	printf("��������Ҫɾ�������߲���һ�����ֲ��Ϣ����ֲ���char[5]��\n");
	scanf("%s", tempYear);
	getchar();
	PInfo p3 = NULL, p4 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	while (p3->VegCode != temp)												//�ж��Ƿ��ҵ�
	{
		p3 = p3->nextinfo;
		p4 = p4->nextinfo;
		if (p4 == NULL)                                                   //����Ϣ�����꣬����һ�������Ӧ����Ϣ��
		{
			p1 = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
		}
	}
	PPlan p5, p6, pb=NULL;                                                 //pb������ʾǰ���Ǹ�,p5�ǵ�ǰ��,p6����һ����Ĭ�ϱض����ҵ������������Ҫ��Ӷ����ж�����
	PInfo ptemp = NULL;
	ptemp = p3;
	p5 = p3->nextplan;
	p6 = p5->next;
	while (strcmp(p5->PlanYear, tempYear) != 0)								//�ж��Ƿ��ҵ�
	{
		pb = p5;
		p5 = p5->next;
		p6 = p6->next;
	}
	if (pb == NULL)                                                       //pb==NULL�������ζ�Ŵ�ʱp5�ƻ��ڵ�Ϊ��Ϣ�ڵ����ĵ�һ���ƻ��ڵ㣬��pb��ʱ����p5��ǰһ���ƻ��ڵ������Ϣ�ڵ�
	{
		ptemp->nextplan = p6;
		p5->next = NULL;
	}
	else                                                                   //��Ϊ�ռ��ҵ��˼ƻ����е�p5�Լ���ǰ��ڵ�
	{
		pb->next = p6;
		p5->next = NULL;
	}
	printf("ɾ����ɣ�Successfully Deleted��\n");
	system("pause");
}




//ʵ�ְ����������������ڳ��ڲ����ޡ�
void searchType(int temp)
{
	int n = 1;                                                           //�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	int i = 1; 
	int j = 1;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
    PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p->TypeCode != temp)
	{
		p = p->nexttype;
	}
	
	printf("�����ţ�%d    �������ƣ�%s \n", p->TypeCode, p->TypeName);
    headi = p->nextinf;
    px = headi;
	while (px != NULL)
	{
		px = px->nextinfo;
		suminfo++;
	}
	px = headi;
    for(i=1;i<suminfo;i++)
    {
        printf("***�����룺%d   �߲˱�ţ�%d    ���ƣ�%s    Ӫ���ɷ֣�%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
		pxx = px->nextplan;
		while (pxx != NULL)
		{
			pxx = pxx->next;
			sumplan++;
		}
		pxx = px->nextplan;
		for (j = 1; j < sumplan; j++)
		{
			printf("         ---�߲˱�ţ�%d   ��ţ�%d   �����%d   ������%f   ��ݣ�%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
			pxx = pxx->next;
		}
        px=px->nextinfo;
		sumplan = 0;
    }
	suminfo = 0;
    
	i = 1;
	n = 1;
	j = 1;

    system("pause");
}




//ʵ���Ӵ��ж�����ڲ���Ϊ�����ַ��������ڲ���Ϊһ���ַ�ָ�롣
char* isZich(char* s, char* t)                              //tΪ�Ӵ���sΪ�������ز�Ϊ�������Ӵ����������ִ�
{
	int i, j, k = 0, slen, tlen;
	char* p = NULL;

	slen = strlen(s);
	tlen = strlen(t);
	for (i = 0; i < slen; i++) {
		j = i;
		while (s[j] == t[k]) 
		{
			k++;
			j++;
		}
		if (k >= tlen) 
		{
			p = &s[i];
			return p;
		}
		k = 0;
	}
	return p;
}





//ʵ�ְ����������������ڳ��ڲ����ޡ�
void searchZich()
{
	printf("��������Ҫ��ѯ�����߲����Լ������Ӵ���char[8] char[6])\n");
	char tempty[8];
	char tempzi[8];
	char tempName[8];
	scanf("%s", tempty);
	scanf("%s", tempzi);
	int n = 1;                                //�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	int i = 1;
	int j = 1;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (strcmp(p->TypeName,tempty)!=0)
	{
		p = p->nexttype;
	}
	printf("�����ţ�%d    �������ƣ�%s \n", p->TypeCode, p->TypeName);
	headi = p->nextinf;
	px = headi;
	while (px != NULL)
	{
		px = px->nextinfo;
		suminfo++;
	}
	px = headi;
	for (i = 1; i < suminfo; i++)
	{
		sprintf(tempName, "%s", px->VegName);
		char* po = isZich(tempName, tempzi);
		if (po!= NULL)
		{
			printf("***�����룺%d   �߲˱�ţ�%d    ���ƣ�%s    Ӫ���ɷ֣�%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan; j++)
			{
				printf("         ---�߲˱�ţ�%d   ��ţ�%d   �����%d   ������%f   ��ݣ�%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
				pxx = pxx->next;
			}
		}
		px = px->nextinfo;
		sumplan = 0;
	}
	suminfo = 0;

	i = 1;
	n = 1;
	j = 1;

	system("pause");
}




//ʵ�ְ��������Ӫ���Ӵ���������ڳ��ڲ����ޡ�
void searchFen()
{
	printf("��������Ҫ��ѯ�ķ������Լ�Ӫ���ɷ��Ӵ���int char[20])\n");
	int temp=0;
	char tempzi[20];
	char tempNu[50];
	scanf("%d", &temp);
	scanf("%s", tempzi);
	int n = 1;                                //�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	int i = 1;
	int j = 1;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p->TypeCode!=temp)
	{
		p = p->nexttype;
	}
	printf("�����ţ�%d    �������ƣ�%s \n", p->TypeCode, p->TypeName);
	headi = p->nextinf;
	px = headi;
	while (px != NULL)
	{
		px = px->nextinfo;
		suminfo++;
	}
	px = headi;
	for (i = 1; i < suminfo; i++)
	{
		sprintf(tempNu, "%s", px->VegNutri);
		char* po = isZich(tempNu, tempzi);
		if (po != NULL)
		{
			printf("***�����룺%d   �߲˱�ţ�%d    ���ƣ�%s    Ӫ���ɷ֣�%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan; j++)
			{
				printf("         ---�߲˱�ţ�%d   ��ţ�%d   �����%d   ������%f   ��ݣ�%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
				pxx = pxx->next;
			}
		}
		px = px->nextinfo;
		sumplan = 0;
	}
	suminfo = 0;

	i = 1;
	n = 1;
	j = 1;

	system("pause");
}




//ʵ�ְ��߲��Ӵ��Լ������������ڳ��ڲ����ޡ�
void searchYear()
{
	printf("��������Ҫ��ѯ�߲������Ӵ��Լ���ݣ�char[6] char[5] )\n");
	char tempzi[8];
	char tempName[8];
	char tempYear[5];
	scanf("%s", tempzi);
	scanf("%s", tempYear);
	int n = 1;                                //�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	int i = 1;
	int j = 1;
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
    {
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
        headi = p->nextinf;
        px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
        for(i=1;i<suminfo;i++)
        {
			sprintf(tempName, "%s", px->VegName);
			char* po = isZich(tempName, tempzi);
			if (po != NULL)
			{
				printf("***�����룺%d   �߲˱�ţ�%d    ���ƣ�%s    Ӫ���ɷ֣�%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
				pxx = px->nextplan;
				while (pxx != NULL)
				{
					pxx = pxx->next;
					sumplan++;
				}
				pxx = px->nextplan;
				for (j = 1; j < sumplan; j++)
				{
					if (strcmp(pxx->PlanYear, tempYear) == 0)
						printf("         ---�߲˱�ţ�%d   ��ţ�%d   �����%d   ������%f   ��ݣ�%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
					pxx = pxx->next;
				}
			}
            px=px->nextinfo;
			sumplan = 0;
        }
        p = p->nexttype;
		suminfo = 0;
    }
	i = 1;
	n = 1;
	j = 1;

    system("pause");
}




//ʵ�ְ��߲�������������ڳ��ڲ����ޡ�
void searchName()
{
	printf("��������Ҫ��ѯ�߲����ƣ�char[8])\n");
	char tempName[8];
	scanf("%s", tempName);
	
	FILE* fp;
	if ((fp = fopen("������ͳ�Ʊ�.csv", "w+")) == NULL)         //�����߲�������Ϣ
		Failure();
	char a2[2] = "\n\0";
	char b1[5] = "���\0";
	char b2[9] = "�߲�����\0";
	char b3[9] = "��������\0";
	char b4[9] = "��ֲ���\0";
	char b5[9] = "�ջ�����\0";
	fprintf(fp, "%s,%s,%s,%s,%s", b1, b2, b3, b4, b5);
	fprintf(fp, "%s", a2);
	
	
	int n = 1;                                //�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	int i = 1;
	int j = 1;
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
	{
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
		headi = p->nextinf;
		px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
		for (i = 1; i < suminfo; i++)
		{
			if (strcmp(px->VegName, tempName) == 0)
			{
				printf("***�����룺%d   �߲˱�ţ�%d    ���ƣ�%s    Ӫ���ɷ֣�%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
				pxx = px->nextplan;
				while (pxx != NULL)
				{
					pxx = pxx->next;
					sumplan++;
				}
				pxx = px->nextplan;
				for (j = 1; j < sumplan; j++)
				{
					printf("         ---�߲˱�ţ�%d   ��ţ�%d   �����%d   ������%f   ��ݣ�%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
					
					fprintf(fp, "%s,%s,%s,%d,%f", pxx->PlanYear, px->VegName,p->TypeName, pxx->PlanArea, pxx->PlanWeight);
					fprintf(fp, "%s", a2);
													            //�Զ������������ļ������Ҫ��ĵ�һ��������ͳ�Ʊ�
					pxx = pxx->next;
				}
			}
			px = px->nextinfo;
			sumplan = 0;
		}
		p = p->nexttype;
		suminfo = 0;
	}
	i = 1;
	n = 1;
	j = 1;


	printf("\n\n");                                            //�Զ������������ļ�,���Ҫ��ĵ�һ��
	printf("���߲˵���ֲ��Ϣ�Ѿ�������������ͳ�Ʊ�.csv\n\n");
	
	
	fclose(fp);
	fp = NULL;

	system("pause");
}




//ʵ��ͳ��ĳ���߲������е��߲���������ڲ���Ϊ����ʵ����������һ���߲ˣ����ڲ����ޡ�
void countSum(int temp)
{
	int n = 1;													//�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	int i = 1;
	int j = 1;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p->TypeCode != temp)
	{
		p = p->nexttype;
	}

	printf("�����ţ�%d    �������ƣ�%s \n", p->TypeCode, p->TypeName);
	headi = p->nextinf;
	px = headi;
	while (px != NULL)
	{
		px = px->nextinfo;
		suminfo++;
	}
	px = headi;
	printf("��ǰ���������е��߲�����Ϊ��%d  \n", suminfo-1);
	system("pause");
}




//ʵ��ͳ�ƺ���ĳӪ���ɷֵ��߲���Ϣ����ʾ����ڲ���Ϊ�ַ�ָ�룬ָ��Ӫ���ɷ��Ӵ������ڲ����ޡ�
void countNu(char* s)
{
	int n = 1;                                //�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	int i = 1; int j = 1;
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
    PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
    {
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
        headi = p->nextinf;
        px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
        for(i=1;i<suminfo;i++)
        {
			char tempNu[50];
			sprintf(tempNu, "%s", px->VegNutri);
			char* po = isZich(tempNu, s);
			if (po != NULL)
				printf("%s\n", px->VegName);
            px=px->nextinfo;
        }
        p = p->nexttype;
		suminfo = 0;
    }
	i = 1;
	n = 1;
	j = 1;
    system("pause");
}




//ʵ��ͳ��ĳһ������߲���Ϣ�����ջ����������������ʾ�Լ������״ͳ��ͼ����ڳ��ڲ�����
void count1Year()
{
	char year[5];
	scanf("%s", year);
	struct temp {
		float weight;
		char typeName[8];
		int area;
	}temp[10], zancun;
	int i = 1; int j = 1;
	for (i = 1; i < 10; i++)                  //��1��ʼʹ�ã�0��������
	{
		temp[i].weight = 0;
		temp[i].area = 0;                     //typeNameδ��ʼ������������Ϊ�ж�����
	}
	int n = 1;                                //�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	i = 1; j = 1;
	int k = 1;
	int flag = 0;                             //��������Ƿ���ж�temp���鸳ֵ���������ж��Ƿ�k����
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	int sum = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
	{
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
		headi = p->nextinf;
		px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
		for (i = 1; i < suminfo; i++)
		{
			//printf("%d  %d  %s  %s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan; j++)
			{
				if ((strcmp(year, pxx->PlanYear) == 0))
				{
					temp[k].weight += pxx->PlanWeight;
					temp[k].area += pxx->PlanArea;
					sprintf(temp[k].typeName, "%s", p->TypeName);
					flag = 1;
				}
				pxx = pxx->next;
				
			}
			px = px->nextinfo;
			sumplan = 0;
			if (((i + 1) >= suminfo) && flag == 1)
			{
				k++;                         //ͬһ���߲��µļƻ��ۼӣ��ֱ��ò�ͬ�±�Ľṹ����洢
				flag = 0;
			}
		}
		p = p->nexttype;
		suminfo = 0;
	}
	i = 1;
	n = 1;
	j = 1;
	float tweight;
	for (i = 1; i < 10; i++)
	{
		if (temp[i].area != 0)
			sum++;                          //���м�����Ч����һ��ʼ
	}

	for (i = 1; i <= sum; i++)              //����
	{
		for (j = 1; j <= sum - i; j++)
		{
			if (temp[j + 1].weight > temp[j].weight)
			{
				zancun = temp[j + 1];
				temp[j + 1] = temp[j];
				temp[j] = zancun;           //���a[j + 1]>a[j],�������������Ԫ�ػ�����Ŀ�İ��������ŵ�ǰ�ߣ�
			}
			else
			{
				continue;
			}
		}
	}

	for (i = 1; i <= sum; i++)
	{
		printf("�������ࣺ%s    �������%d    ��������%f\n",  temp[i].typeName, temp[i].area, temp[i].weight);
	}

	i = 1; j = 1;
	printf("\n\n");
	for (i = 10; i >= 1; i--)
	{
		//printf("|\n");
		printf("%d -   ",10*i);
		for (j = 1; j <= sum; j++)
		{
			if (temp[j].weight >= (10 * i))
				printf("#####     ");
		}
		printf("\n");
	}
	printf(" 0 ------------------------------------------------------------------->");


	printf("\n\n");                                            //�Զ������������ļ�,���Ҫ��ĵڶ��������ͳ�Ʊ�
	printf("������߲���ֲ��Ϣ�Ѿ������������ͳ�Ʊ�.csv\n\n");
	FILE* fp;
	if ((fp = fopen("�����ͳ�Ʊ�.csv", "w+")) == NULL)         //�����߲�������Ϣ
		Failure();
	char a2[2] = "\n\0";
	char b1[5] = "���\0";
	char b2[9] = "��������\0";
	char b3[9] = "��ֲ���\0";
	char b4[11] = "�ջ�������\0";
	fprintf(fp, "%s,%s,%s,%s", b1, b2, b3, b4);
	fprintf(fp, "%s", a2);
	for (i = 1; i <= sum; i++)
	{
		fprintf(fp, "%s,%s,%d,%f", year, temp[i].typeName, temp[i].area, temp[i].weight);
		fprintf(fp, "%s", a2);
	}
	fclose(fp);
	fp = NULL;
	system("pause");
}




//ʵ��ͳ����ֹ��ݼ�ĳ�߲���Ϣ�����ջ����������������ʾ����ڳ��ڲ�����
void count2Years()
{
	struct temp {
		float weight;
		char VegName[8];
		char typeName[8];
		int area;
	}temp[20],zancun;
	int i = 1; int j = 1;
	for (i = 1; i < 20; i++)                  //��1��ʼʹ�ã�0��������
	{
		temp[i].weight = 0;
		temp[i].area = 0;                     //vegName��typeNameδ��ʼ������������Ϊ�ж�����
	}
	char qi[5];
	char zhi[5];
	scanf("%s", qi);
	scanf("%s", zhi);
	int n = 1;                                //�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	i = 1;j = 1;
	int k = 1;
	int flag = 0;                             //��������Ƿ���ж�temp���鸳ֵ���������ж��Ƿ�k����
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	int sum = 0;
	PType p;
    PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
    {
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
        headi = p->nextinf;
        px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
        for(i=1;i<suminfo;i++)
        {
            //printf("%d  %d  %s  %s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan;j++)
			{
				if ((strcmp(qi, pxx->PlanYear) <= 0) && (strcmp(pxx->PlanYear, zhi) <= 0))
				{
					//printf("              %d %d %d %f %s\n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
					temp[k].weight += pxx->PlanWeight;
					temp[k].area += pxx->PlanArea;
					sprintf(temp[k].VegName, "%s", px->VegName);
					sprintf(temp[k].typeName, "%s", p->TypeName);
					flag = 1;
				}
				pxx = pxx->next;
				if (((j + 1) >= sumplan) && flag == 1)
				{
					k++;                     //ͬһ���߲��µļƻ��ۼӣ��ֱ��ò�ͬ�±�Ľṹ����洢
					flag = 0;
				}
			}
            px=px->nextinfo;
			sumplan = 0;
        }
        p = p->nexttype;
		suminfo = 0;
    }
	i = 1;
	n = 1;
	j = 1;
	float tweight;
	for (i = 1; i < 20; i++)
	{
		if (temp[i].area != 0)
			sum++;                          //���м�����Ч����һ��ʼ
	}

	for (i = 1; i <=sum; i++)             //����
	{
		for (j =1; j <=sum-i; j++)       
		{
			if (temp[j + 1].weight > temp[j].weight)
			{
				zancun = temp[j + 1];
				temp[j + 1] = temp[j];
				temp[j] = zancun;           //���a[j + 1]>a[j],�������������Ԫ�ػ�����Ŀ�İ��������ŵ�ǰ�ߣ�
			}
			else
			{
				continue;
			}
		}
	}
	for (i = 1; i <= sum; i++)
	{
		printf("�߲����ƣ�%s    �������ࣺ%s    �������%d    ��������%f\n", temp[i].VegName, temp[i].typeName, temp[i].area, temp[i].weight);
	}

    system("pause");
}




//�����ڼ��ֱ�ۣ�ʵ������Ļ�ϴ�ӡ��ǰ����ϵͳ�е���Ϣ����ڳ��ڲ�����
void printData()
{
	int n = 1;                                //�������type & info & plan���ڵ���Ϣ��ע�����һ�������
	int i = 1; int j = 1;
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
    PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
    {
		printf("�����ţ�%d    �������ƣ�%s\n", p->TypeCode, p->TypeName);
        headi = p->nextinf;
        px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
        for(i=1;i<suminfo;i++)
        {
            printf("*****�����룺%d    �߲˱�ţ�%d    �߲����ƣ�%s    Ӫ���ɷ֣�%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan; j++)
			{
				printf("             ----- ���룺%d   �߲˱�ţ�%d   �����%d    �ջ�������%f    ��ݣ�%s  \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
				pxx = pxx->next;
			}
            px=px->nextinfo;
			sumplan = 0;
        }
        p = p->nexttype;
		suminfo = 0;
    }
	i = 1;
	n = 1;
	j = 1;

    system("pause");


}




//ʵ�ֱ��桢��������ϵͳ�е���Ϣ����һ��ʼ���ص��ļ��У���ڳ��ڲ�����
void save()
{
	PType p;
	PType p1;
	FILE* fp;
	if ((fp = fopen("�߲�����.csv", "w+")) == NULL)         //�����߲�������Ϣ
		Failure();
	char delims[] = ",";
	char* line, * record;
	char buffer[1024];
	int i = 1, j = 1;
	char a1[9] = "������\0";
	fprintf(fp, "%s", a1);
	p1 = headv->nexttype;                                   //p1ָ��ǰ��pָ����һ��
	p = p1->nexttype;
	while (p != NULL)
	{
		fprintf(fp, ",%d", p1->TypeCode);
		p1 = p1->nexttype;
		p = p->nexttype;
	}
	char a2[2] = "\n\0";
	fprintf(fp, "%s", a2);
	char a3[9] = "��������\0";
	fprintf(fp, "%s", a3);
	p1 = headv->nexttype;
	p = p1->nexttype;
	while (p != NULL)
	{
		fprintf(fp, ",%s", p1->TypeName);
		p1 = p1->nexttype;
		p = p->nexttype;
	}
	fprintf(fp, "%s", a2);
	p1 = headv->nexttype;
	p = p1->nexttype;
	fclose(fp);
	fp = NULL;


	FILE* fp2;
	if ((fp2 = fopen("�߲���Ϣ.csv", "w+")) == NULL)         //д���߲�������Ϣ
		Failure();
	i = 1; j = 1;
	int flag = 0;
	char b1[9] = "�߲˱��\0";
	char b2[9] = "�߲�����\0";
	char b3[7] = "������\0";
	char b4[9] = "Ӫ���ɷ�\0";
	fprintf(fp2, "%s,%s,%s,%s", b1,b2,b3,b4);
	fprintf(fp2, "%s", a2);
	p1 = headv->nexttype;
	p = p1->nexttype;
	PInfo p3 = NULL, p4 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	while (i != (hang2+1))
	{
		while ((p3->VegCode != i))
		{
			if (p4 != NULL)
			{
				p3 = p3->nextinfo;
				p4 = p4->nextinfo;
			}
			if (p4 == NULL)
			{
				p1 = p1->nexttype;
				if (p1->nexttype == NULL)
				{
					flag = 1;
					break;
				}
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
			}
		}
		if (flag == 1)
		{
			i++;
			p1 = headv->nexttype;
			p = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
			flag = 0;
			continue;
		}
		fprintf(fp2, "%d,%s,%d,%s", p3->VegCode,p3->VegName,p3->VegType,p3->VegNutri);
		fprintf(fp2, "%s", a2);
		i++;
		p1 = headv->nexttype;
		p = p1->nexttype;
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
    }
	p1 = headv->nexttype;
	p = p1->nexttype;
	fclose(fp2);
	fp2 = NULL;


	FILE* fp3;
	if ((fp3 = fopen("��ֲ��Ϣ.csv", "w+")) == NULL)         //д����ֲ�ƻ���Ϣ
		Failure();
	i = 1; j = 1; flag = 0;
	char c1[5] = "���\0";
	char c2[9] = "�߲˱��\0";
	char c3[9] = "��ֲ���\0";
	char c4[9] = "�ջ�����\0";
	char c5[9] = "��ֲ���\0";
	fprintf(fp3, "%s,%s,%s,%s,%s", c1, c2, c3, c4,c5);
	fprintf(fp3, "%s", a2);
	p1 = headv->nexttype;
	p = p1->nexttype;
	p3 = NULL, p4 = NULL;
	PPlan p5 = NULL, p6 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	p5 = p3->nextplan;
	p6 = p5->next;
	while (i != (hang3 + 1))
	{
		while ((p5->PlanCode != i))
		{
			if (p6 != NULL)                             //��ֹ��ʱp5�Ѿ�ָ�����һ��������ڵ���p6��ΪNULL
			{
				p5 = p5->next;
				p6 = p6->next;
			}
			if (p6 == NULL)
			{
				p3 = p3->nextinfo;
				p4 = p4->nextinfo;
				p5 = p3->nextplan;
				if(p5!=NULL)
					p6 = p5->next;                      //��ֹ��p5ΪNULLʱ��������ҵ��´���
			}
			if (p4 == NULL)                             //p4Ϊ��˵������Ϣ��Ѱ�����
			{
		Label:	p1 = p1->nexttype;
				if (p1->nexttype == NULL)               //flag==1˵��ȫ������Ҳû�ҵ�plancodeΪi����ֲ�ƻ�
				{
					flag = 1;
					break;
				}
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
				p5 = p3->nextplan;
				if(p5!=NULL)
					p6 = p5->next;
				while(p5 == NULL)                           //���������߲�û��������ļƻ���һֱ�ҵ�һ���мƻ����߲˵Ļ�����Ϣ
				{
					p3 = p3->nextinfo;
					p4 = p4->nextinfo;
					p5 = p3->nextplan;
					if (p5 != NULL)
						p6 = p5->next;                      //��ֹ��p5ΪNULLʱ��������ҵ��´���
					if (p4 == NULL)
					{
						goto Label;                         //Ϊ�󷽱�ʹ��һ��goto���ڵ�ǰ������Ϣ��������Ϻ���ת����һ������ڵ��Ӧ����һ����Ϣ����Ҳ����ͨ��ѭ����flag����ʵ�ִ˹���
					}
				}
			}
		}
		if (flag == 1)
		{
			i++;
			p1 = headv->nexttype;
			p = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
			p5 = p3->nextplan;
			p6 = p5->next;
			flag = 0;
			continue;
		}
		fprintf(fp3, "%d,%d,%d,%f,%s", p5->PlanCode, p5->PlanVegCode, p5->PlanArea, p5->PlanWeight,p5->PlanYear);
		fprintf(fp3, "%s", a2);
		i++;
		p1 = headv->nexttype;
		p = p1->nexttype;
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
		p5 = p3->nextplan;
		p6 = p5->next;
	}
	p1 = headv->nexttype;
	p = p1->nexttype;
	fclose(fp3);
	fp3 = NULL;


}
