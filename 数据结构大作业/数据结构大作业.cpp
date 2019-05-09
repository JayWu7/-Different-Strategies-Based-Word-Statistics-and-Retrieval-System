// ���ݽṹ����ҵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#define	maxsize	5000

using	namespace std;

struct Word
{
	string	w="";
	int num=0;
};

struct SqList//˳���
{
	Word	*elem;
	int len=0;
};

typedef	struct LNode//����
{
	Word	data;
	struct LNode	*next;
}LNode,*LinkList;

typedef	struct BSTNode
{
	Word	data;
	struct BSTNode	*lchild, *rchild;
}BSTNode,*BSTree;

struct HashTable
{
	int	n=0;//��¼���ֳ�ͻ�Ĵ���
	Word	data;
};

typedef	struct //��ϣ����
{
	LinkList	L = NULL;
}hash_LNode[maxsize];

void	cover1()
{
	cout << "********************************************************************************" << endl;
	cout << "*********************** ���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1���������Ա�Ĳ���" << endl;
	cout << "2�����ڶ����������Ĳ���" << endl;
	cout << "3�����ڹ�ϣ��Ĳ���" << endl;
	cout << "4���˳�\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover2()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************         �������Ա�Ĳ���         ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1��˳�����" << endl;
	cout << "2���۰����" << endl;
	cout << "3��������һ��\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover3()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************             ˳�����             ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1������˳����˳�����" << endl;
	cout << "2�����������˳�����" << endl;
	cout << "3��������һ��\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover4()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************       ����˳����˳�����       ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1����Ƶͳ��" << endl;
	cout << "2�����ʲ���" << endl;
	cout << "3��������һ��\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover5()
{
	cout << "********************************************************************************" << endl;
	cout << " ***********************       -----���ʲ���-----       ***********************\n" << endl;
	cout << "\n" << endl;
}

void	cover6()
{
	cout << "********************************************************************************" << endl;
	cout << "****************************       -�۰����-       ****************************\n" << endl;
	cout << "\n" << endl;
	cout << "1����Ƶͳ��" << endl;
	cout << "2�����ʲ���" << endl;
	cout << "3��������һ��\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover7()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************       -���������˳�����-       ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1����Ƶͳ��" << endl;
	cout << "2�����ʲ���" << endl;
	cout << "3��������һ��\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover8()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************       -���ڶ����������Ĳ���-       *********************\n" << endl;
	cout << "\n" << endl;
	cout << "1����Ƶͳ��" << endl;
	cout << "2�����ʲ���" << endl;
	cout << "3��������һ��\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover9()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************             ��ϣ����             ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1�����ڿ��ŵ�ַ���Ĺ�ϣ����" << endl;
	cout << "2����������ַ���Ĺ�ϣ����" << endl;
	cout << "3��������һ��\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover10()
{
	cout << "********************************************************************************" << endl;
	cout << "*********************       -���ڿ��ŵ�ַ���Ĺ�ϣ����-       *******************\n" << endl;
	cout << "\n" << endl;
	cout << "1����Ƶͳ��" << endl;
	cout << "2�����ʲ���" << endl;
	cout << "3��������һ��\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover11()
{
	cout << "********************************************************************************" << endl;
	cout << "*********************       -��������ַ���Ĺ�ϣ����-       *********************\n" << endl;
	cout << "\n" << endl;
	cout << "1����Ƶͳ��" << endl;
	cout << "2�����ʲ���" << endl;
	cout << "3��������һ��\n" << endl;
	cout << "��������Ӧ�����ֽ���ѡ��" << endl;
}

void	cover12()
{
	cout << "********************************************************************************\n" << endl;
	cout << "*****************************       -���ʲ���-       ***************************\n" << endl;
	cout << "\n\n";
}


void	qsort_sqlist(SqList	&jay, int low, int high)//low=0,high=len-1,����
{
	if (low >= high)//����дlow==high
		return;
	int	i, j;
	i = low;
	j = high;
	Word	key;
	key = jay.elem[i];
	while (i < j)
	{
		while (i < j && (jay.elem[j].w >= key.w))
			j--;
		jay.elem[i] = jay.elem[j];
		while (i < j && (jay.elem[i].w <= key.w))
			i++;
		jay.elem[j] = jay.elem[i];
	}
	jay.elem[i] = key;
	qsort_sqlist(jay, low, i - 1);//�ݹ����
	qsort_sqlist(jay, i + 1, high);
}

void	input_sqlist(SqList &jay)//˳��������
{
	int	i = 0;//�±�
	string s="";//��ʱ�洢����
	char c;//��ʱ�洢��ĸ
	ifstream	in;//���ļ�
	in.open("InFile.txt");//���ļ�
	if (!in)
	{
		cout << "can't open this file\n";
		return;
	}
	while (!in.eof())//��ȡ����
	{
		in.get(c);//��in>>����
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)||c == '\'')//�ж�c�Ƿ�Ϊ��ĸ�� '
		{
			if (c <= 90 && c != '\'')//����Ǵ�д��ĸת��ΪСд��ĸ
				c = c + 32;
			s = s + c;
		}
		else//�ɹ���ȡһ������
		{
			if (s != "")//�ų��������ֶ������ĸ�ַ������
			{
				int flag = 0;//�жϸõ����Ƿ��Ѵ�����˳�����
				for (int j = 0; j < i; j++)
				{
					if (s == jay.elem[j].w)
					{
						flag = 1;//�õ��ʴ���˳�����
						jay.elem[j].num++;
						break;
					}
				}
				if (flag == 0)
				{
					jay.elem[i].w = s;//���õ��ʴ��˳���
					jay.elem[i].num++;
					i++;
				}
				s = "";//s���
			}
		}
	}
	jay.len = i;
	in.close();
}

int	input_LinkList(LinkList &L)//���������
{
	LinkList	r,p;
	int	l ;//��¼������
	l = 0;
	string s = "";//��ʱ�洢����
	char c;//��ʱ�洢��ĸ
	ifstream	in;//���ļ�
	in.open("InFile.txt");//���ļ�
	if (!in)
	{
		cout << "can't open this file\n";
		return 0;
	}
	while (!in.eof())//��ȡ����
	{
		in.get(c);//��in>>����
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ||c == '\'')//�ж�c�Ƿ�Ϊ��ĸ
		{
			if (c <= 90 && c != '\'')//����Ǵ�д��ĸת��ΪСд��ĸ
				c = c + 32;
			s = s + c;
		}
		else//�ɹ���ȡһ������
		{
			if (s != "")//�ų��������ֶ������ĸ�ַ������
			{
				r = L->next;//r��ʼ��Ϊ��Ԫ��㣬������������
				p = L;//p��ʼ��Ϊͷ��㣬������¼r��ǰ�ý��
				while (r)
				{
					if (s == r->data.w)//�õ������ڱ���
					{
						r->data.num++;
						break;
					}
					p = r;
					r = r->next;
				}
				if (r == NULL)//���ʲ����ڱ���
				{
					l++;
					LinkList	q;//�����½��
					q = new	LNode;
					q->data.w = s;
					q->data.num++;
					p->next = q;
					q->next = NULL;
				}
				s = "";//s���
			}
		}
	}
	in.close();
	return	l;//����������
}

void	insertbst(BSTree &T, string e)//�����������Ĳ���
{
	if (!T)//TΪ�գ��ҵ�����λ��
	{
		BSTree	s;
		s = new	BSTNode;
		s->data.w = e;
		s->data.num++;
		s->lchild = s->rchild = NULL;//Ҷ�ӽ�㣬���ӣ��Һ��Ӷ�Ϊ��
		T = s;
	}
	else
		if (e < T->data.w)
			insertbst(T->lchild, e);
		else
			if (e > T->data.w)
				insertbst(T->rchild, e);
			else//����˵��ʺ͵�ǰ���ĵ���������ȣ���������1
				T->data.num++;
}

void	input_bst(BSTree	&T)//��������������
{
	string s = "";//��ʱ�洢����
	char c;//��ʱ�洢��ĸ
	ifstream	in;//���ļ�
	in.open("InFile.txt");//���ļ�
	if (!in)
	{
		cout << "can't open this file\n";
		return;
	}
	while (!in.eof())//��ȡ����
	{
		in.get(c);//��in>>����
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)|| c == '\'')//�ж�c�Ƿ�Ϊ��ĸ
		{
			if (c <= 90 && c != '\'')//����Ǵ�д��ĸת��ΪСд��ĸ
				c = c + 32;
			s = s + c;
		}
		else//�ɹ���ȡһ������
		{
			if (s != "")//�ų��������ֶ������ĸ�ַ������
				insertbst(T, s);
			s = "";
		}
	}
}

int	Hash(string s)//��ϣ����   ����ĸ����ĸ���е��±� �� β��ĸ����ĸ���е��±�
{
	char	a, b;//aΪs����ĸ��bΪĩ��ĸ
	a = s[0];
	b = s[s.length() - 1];
	return	(int(a - 96)*int(b - 96)) % maxsize;
}


void	input_hash_openadd(HashTable	HT[])//���ڿ��ŵ�ַ���Ĺ�ϣ���ң�������ϣ��
{
	string s = "";//��ʱ�洢����
	char c;//��ʱ�洢��ĸ
	ifstream	in;//���ļ�
	int	key,n,k;//key��¼�������ϣ������ֵ,n��¼���ֳ�ͻ�Ĵ�����k���������ͻ
	in.open("InFile.txt");//���ļ�
	if (!in)
	{
		cout << "can't open this file\n";
		return;
	}
	while (!in.eof())//��ȡ����
	{
		in.get(c);//��in>>����
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)|| c == '\'')//�ж�c�Ƿ�Ϊ��ĸ
		{
			if (c <= 90 && c != '\'')//����Ǵ�д��ĸת��ΪСд��ĸ
				c = c + 32;
			s = s + c;
		}
		else//�ɹ���ȡһ������
		{
			if (s != "") // �ų��������ֶ������ĸ���ַ����
			{
				k = 0;
				n = 0;
				key = Hash(s);
				while (1)
				{
					if (HT[key].data.w == s)//�õ����Ѵ���
					{
						HT[key].data.num++;
						HT[key].n = n;
						break;
					}
					else
					{
						if (HT[key].data.w == "")//�µ���
						{
							HT[key].data.w = s;
							HT[key].data.num++;
							HT[key].n = n;
							break;
						}
						else//������ͻ
						{
							k++;
							key = (key + k) % maxsize;
							n++;
						}
					}
				}
				s = "";
			}
		}
	}
}

void	input_hash_linklist(hash_LNode HT)//��������ַ���Ĺ�ϣ���ң�������ϣ����
{
	LinkList	a, b;
	string s = "";//��ʱ�洢����
	char c;//��ʱ�洢��ĸ
	ifstream	in;//���ļ�
	int	key;//key��¼�������ϣ������ֵ
	in.open("InFile.txt");//���ļ�
	if (!in)
	{
		cout << "can't open this file\n";
		return;
	}
	while (!in.eof())//��ȡ����
	{
		in.get(c);//��in>>����
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)||c == '\'')//�ж�c�Ƿ�Ϊ��ĸ
		{
			if (c <= 90 && c != '\'')//����Ǵ�д��ĸת��ΪСд��ĸ
				c = c + 32;
			s = s + c;
		}
		else//�ɹ���ȡһ������
		{
			if (s != "") // �ų��������ֶ������ĸ���ַ����
			{
				key = Hash(s);
				if (!HT[key].L)//��keyֵ,�µ���
				{
					LinkList	q;
					q = new	LNode;
					q->data.w = s;
					q->data.num = 1;
					q->next = NULL;
					HT[key].L = q;
				}
				else
				{
					a = HT[key].L;//aΪ��ǰkeyֵ�������Ԫ��㣬������������
					while (a)
					{
						if (a->data.w == s)
						{
							a->data.num++;
							break;
						}
						b = a;//b������¼a��ǰ�ý��
						a = a->next;
					}
					if (!a)//�µ���
					{
						LinkList	q;
						q = new	LNode;
						q->data.w = s;
						q->data.num = 1;
						q->next = NULL;
						b->next = q;
					}
				}
			}
			s = "";
		}
	}
}

void	outfile_hash_linklist(hash_LNode HT, string f)//д�ļ�����������ַ����ϣ
{
	LinkList	p;
	SqList	jay;
	int j = 0;//˳����±�
	jay.elem = new	Word[maxsize];
	for (int i = 0; i < maxsize; i++)//����ϣ�����������ת�Ƶ�˳���
	{
		if (HT[i].L)
		{
			p = HT[i].L;
			while (p)
			{
				jay.elem[j] = p->data;
				j++;
				p = p->next;
			}
		}
	}
	jay.len = j;
	qsort_sqlist(jay, 0, jay.len - 1);//���ÿ���
	ofstream	outfile(f);//д���ļ�
	outfile << jay.len << endl;
	for (int i = 0; i < jay.len; i++)
		outfile << jay.elem[i].w << "  " << jay.elem[i].num << endl;
	cout << "��Ƶͳ�Ƴɹ���\n";
}

void	outfile_hash(HashTable	HT[],string	f)//�������ļ������ڿ��ŵ�ַ����ϣ
{
	LinkList	L,r,p;//����ϣ���������ת�Ƶ��������������
	L = new	LNode;
	L->next = NULL;
	p = L;
	int	n = 0;
	for (int i = 0; i < maxsize; i++)
	{
		if (HT[i].data.w != "")//�ڹ�ϣ����ȡ��һ������
		{
			r = L->next;
			n++;
			while (r&&r->data.w < HT[i].data.w)//�ҵ���һ����HT[i]������С�Ľ��
			{
				p = r;
				r = r->next;
			}
			LinkList	q;//�����½��
			q = new	LNode;
			q->data = HT[i].data;
			p->next = q;
			q->next = r;
		}	
	}//�������
	ofstream	outfile(f);
	outfile << n << endl;
	while (L->next)
	{
		L = L->next;
		outfile << L->data.w << "  " << L->data.num << endl;
	}
	cout << "��Ƶͳ�Ƴɹ���\n";
}

void	InOrder_traver(BSTree T, Word w[] ,int &i)//�������������
{
	if(T)
	{
		InOrder_traver(T->lchild, w, i);
		w[i] = T->data;
		i++;//i���Ϊword����
		InOrder_traver(T->rchild, w, i);
	}
}

void	outfile_bst(BSTree T,string s)//���ڶ���������ͳ�ƴ�Ƶ
{
	ofstream	outfile(s);
	Word	*w;
	int	i = 0;
	w = new	Word[maxsize];
	InOrder_traver(T, w, i);//��������������������������������������ط���������
	outfile << i  << endl;
	for (int j = 0; j < i; j++)
	{
		outfile << w[j].w << "  " << w[j].num << endl;
	}
	cout << "��Ƶͳ�Ƴɹ���\n";
}


void	outfile_sqlist(SqList jay,string f)//�������ļ�����Ƶͳ�ƣ�˳���
{
	ofstream	outfile(f);
	outfile << jay.len << endl;
	for (int i = 0; i < jay.len; i++)
		outfile << jay.elem[i].w << "  " << jay.elem[i].num << endl;
	cout << "��Ƶͳ�Ƴɹ���\n";
}

void	outfile_LinkList(LinkList L, string f,int l)//�������ļ�����Ƶͳ��,����
{
	ofstream	outfile(f);
	LinkList	r;
	r = L->next;
	outfile << l << endl;
	while (r)
	{
		outfile << r->data.w << "  " << r->data.num << endl;
		r = r->next;
	}
	cout << "��Ƶͳ�Ƴɹ�\n";
}

void	sort_linklist(LinkList &L, int n)//��������
{
	LinkList	a, b, q;
	int i, j;
	for (i = 0; i < n - 1; i++)//ð��
	{
		q = L;//q��¼a��ǰ�����
		a = L->next;//aΪ��ǰ���
		b = a->next;//b��¼a�ĺ��ý��
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a->data.w > b->data.w)
			{
				a->next = b->next;
				q->next = b;
				q = b;
				q->next = a;
			}
			else
			{
				q = q->next;
				a = a->next;
			}
			b = a->next;
		}
	}
}

int	findword_sqlist()//���ʲ��ң����Ա�
{
	SqList	wu;
	wu.elem = new	Word[maxsize];
	string	s;//�����ҵ���
	int	n = 0;//�Ƚϴ���
	int	flag = 0;//�жϵ����Ƿ����
	int m;//��¼�����ҵ����±�
	time_t	start, end;//��¼ʱ��
	float	Asl,l;
	cout << "����������ҵĵ��ʣ�";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//����Ǵ�д��ĸ��ת��ΪСд
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	input_sqlist(wu);//���ļ�������ݶ������Ա�
	l = wu.len;
	Asl = (l + 1) / 2;//����asl
	start = clock();//��ʼʱ��
	for (int i = 0; i < wu.len; i++)
	{
		n++;
		if (wu.elem[i].w == s)
		{
			flag = 1;//���ҳɹ�
			m = i;
			break;
		}
	}
	end = clock();//����ʱ��
	if (flag == 1)
	{
		cout << "\n�˵��ʵĴ�ƵΪ�� " << wu.elem[m].num << endl;
		cout << "���Ҹõ�������ʱ��Ϊ�� " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "ƽ�����ҳ��ȣ� " << Asl << endl;
		cout << "���Ҹõ��ʵıȽϴ����� " << n << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
	cout << "\n�밴��������أ�" << endl;
	string c;//����һ�������ַ�
	cin >> c;
	return	1;
}

int	findword_linklist()//���ʲ��ң�����
{
	LinkList	L,r;
	L = new	LNode;
	L->next = NULL;
	string	s;//�����ҵ���
	int	n = 0;//�Ƚϴ���
	time_t	start, end;//��¼ʱ��
	float	Asl, l;//lΪ������
	cout << "����������ҵĵ��ʣ�";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//����Ǵ�д��ĸ��ת��ΪСд
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	l=input_LinkList(L);//���ļ��е����ݶ�������
	r = L->next;//r��ʼ��Ϊ��Ԫ���
	Asl = (l + 1) / 2;
	start = clock();
	while(r)
	{
		n++;
		if (r->data.w == s)
			break;
		r = r->next;
	}
	end = clock();
	if (r)//���ҳɹ�
	{
		cout << "\n�˵��ʵĴ�ƵΪ�� " << r->data.num << endl;
		cout << "���Ҹõ�������ʱ��Ϊ�� " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "ƽ�����ҳ��ȣ� " << Asl << endl;
		cout << "���Ҹõ��ʵıȽϴ����� " << n << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
	cout << "\n�밴��������أ�" << endl;
	string c;//����һ���ַ�
	cin >> c;
	return	1;
}

int	zheban(SqList wu, int i, int j,string s,int &m,int &n)//�۰���Һ���
{
	n = 0;
	while (i <= j)
	{
		m = (i + j) / 2;
		n++;
		if (s == wu.elem[m].w)
		{
			return	1;
		}
		else
			if (s < wu.elem[m].w)
				j = m - 1;
			else
				i = m + 1;
	}
	return	0;
}

int	zhebanfind(SqList wu)//���ʲ��ң��۰����
{
	int	i, j, n, m;//n���Ƚϴ���
	string	s;//�����ҵ���
	float	sum = 0;//���е��ʵĲ�������
	int	flag = 0;//�жϵ����Ƿ����
	time_t	start, end;//��¼ʱ��
	float	Asl;
	i = 0;
	j = wu.len-1;
	for (int k = 0; k < wu.len; k++)//����asl���������е���
	{
		s = wu.elem[k].w;
		zheban(wu, i, j, s, m, n);
		sum += n;
	}
	Asl = sum / wu.len;
	cout << "����������ҵĵ��ʣ�";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//����Ǵ�д��ĸ��ת��ΪСд
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	start = clock();//��ʼ����
	flag=zheban(wu, i, j, s, m,n);
	end = clock();//���ҽ���
	if (flag == 1)
	{
		cout << "\n�˵��ʵĴ�ƵΪ�� " << wu.elem[m].num << endl;
		cout << "���Ҹõ�������ʱ��Ϊ�� " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "ƽ�����ҳ��ȣ� " << Asl << endl;
		cout << "���Ҹõ��ʵıȽϴ����� " << n << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
	cout << "\n�밴��������أ�" << endl;
	string c;//����һ���ַ�
	cin >> c;
	return	1;
}

BSTree	bst_find(BSTree T, string s,int &m)//�ݹ飬�����в��ҵ��� m�����Ҵ���
{
	m++;
	if (!T || s == T->data.w)
		return	T;
	else
		if (T->data.w > s)
			return	bst_find(T->lchild, s, m);
		else
			return	bst_find(T->rchild, s, m);
}

void	Asl_tree(BSTree T,BSTree t, float &n,int &l)//�����������������,��Asl
{
	if (T)
	{
		Asl_tree(T->lchild, t, n, l);
		int	m = 0;
		bst_find(t, T->data.w, m);//���㵱ǰ��㵥�ʵĲ��Ҵ���
		l++;//l��¼���н�����
		n = n + m;
		Asl_tree(T->rchild, t, n, l);
	}
}

void	bst_findword(BSTree T)//���ڶ����������ĵ��ʲ���
{
	BSTree	t;
	string	s;//�����ҵ���
	int	n = 0;//�Ƚϴ���
	float m = 0;//�ܱȽϴ���
	int	l = 0;
	time_t	start, end;//��¼ʱ��
	float	Asl = 0;
	cout << "����������ҵĵ��ʣ�";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//����Ǵ�д��ĸ��ת��ΪСд
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	Asl_tree(T, T,m,l);//��asl
	Asl = m / l;
	start = clock();
	t=bst_find(T, s, n);
	end = clock();
	if (t)
	{
		cout << "\n�˵��ʵĴ�ƵΪ�� " << t->data.num << endl;
		cout << "���Ҹõ�������ʱ��Ϊ�� " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "ƽ�����ҳ��ȣ� " << Asl << endl;
		cout << "���Ҹõ��ʵıȽϴ����� " << n << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
	cout << "\n�밴��������أ�" << endl;
	string c;//����һ���ַ�
	cin >> c;
}

Word	search_hash_openadd(HashTable HT[], string s, int &n)
{
	int	key;
	key = Hash(s);
	n = 1;
	if (HT[key].data.w == "" || HT[key].data.w == s)//��������ͻ
		return	HT[key].data;
	else
	{
		for (int i = 1; i < maxsize; i++)
		{
			n++;
			key = (key + i) % maxsize;
			if (HT[key].data.w == "" || HT[key].data.w == s)
				return	HT[key].data;
		}
	}
}

void	findword_hashadd(HashTable HT[])//���ʲ��ң����ڿ��ŵ�ַ���Ĺ�ϣ����
{
	Word	word;//���ҳɹ����صĵ���
	string	s;//�����ҵ���
	int	n = 0;//�Ƚϴ���
	float m = 0;//�ܱȽϴ���
	int	l = 0;//��������
	time_t	start, end;//��¼ʱ��
	float	Asl = 0;
	cout << "����������ҵĵ��ʣ�";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//����Ǵ�д��ĸ��ת��ΪСд
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	for (int i = 0; i < maxsize; i++)//��asl
	{
		if (HT[i].data.num != 0)//��ϣ��ǰ�±�λ�ô洢�ŵ���
		{
			m += (HT[i].n+1);//�Ƚϴ���Ϊ��ͻ������1
			l++;
		}
	}
	Asl = m / l;
	start = clock();
	word=search_hash_openadd(HT, s, n);
	end = clock();
	if (word.w != "")
	{
		cout << "\n�˵��ʵĴ�ƵΪ�� " << word.num << endl;
		cout << "���Ҹõ�������ʱ��Ϊ�� " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "ƽ�����ҳ��ȣ� " << Asl << endl;
		cout << "���Ҹõ��ʵıȽϴ����� " << n << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
	cout << "\n�밴��������أ�" << endl;
	string c;//����һ���ַ�
	cin >> c;
}

void	findword_hashlinklist(hash_LNode HT)//���ʲ��ң����ڹ�ϣ����ַ��
{
	LinkList	q;
	string	s;//�����ҵ���
	int key, n, l;//key:�����ҵ��ʹؼ��� num:�����ҵ��ʴ�Ƶ n:��ǰ���ʵıȽϴ��� l:���ʸ���
	float m = 0;//�ܱȽϴ���
	l = 0;
	time_t	start, end;//��¼ʱ��
	float	Asl = 0;
	cout << "����������ҵĵ��ʣ�";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//����Ǵ�д��ĸ��ת��ΪСд
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	for (int i = 0; i < maxsize; i++)//�����ܲ��Ҵ���
	{
		n = 0;
		if (HT[i].L)
		{
			q = HT[i].L;
			while (q)
			{
				n++;
				l++;
				m = m + n;
				q = q->next;
			}
		}
	}
	Asl = m / l;
	start = clock();
	key = Hash(s);//�ɹ�ϣ���������ַ
	q = HT[key].L;
	n = 0;
	while (q)//��������
	{
		n++;
		if (q->data.w == s)//���ҳɹ�����ѭ��
		{
			break;
		}
		q = q->next;
	}
	end = clock();
	if (q)
	{
		cout << "\n�˵��ʵĴ�ƵΪ�� " << q->data.num << endl;
		cout << "���Ҹõ�������ʱ��Ϊ�� " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "ƽ�����ҳ��ȣ� " << Asl << endl;
		cout << "���Ҹõ��ʵıȽϴ����� " << n << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
	cout << "\n�밴��������أ�" << endl;
	string c;//����һ���ַ�
	cin >> c;
}

int	shunxufind_sqlist()//����˳���,˳�����
{
	string	s;
	int	t;
	SqList	wu;//����˳���
	wu.elem = new	Word[maxsize];//���ٿռ�
	while(1)
	{
		cover4();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://��Ƶͳ��
			system("CLS");
			input_sqlist(wu);
			qsort_sqlist(wu, 0, wu.len - 1);
			outfile_sqlist(wu, "OutFile1.txt");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2116://���ʲ���
			system("CLS");
			cover12();
			findword_sqlist();
			system("CLS");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2025:
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "���������������������룺" << endl;
		}
	}
}

int	shunxufind_linklist()//��������˳�����
{
	string	s;
	int	t,l;//l��¼������
	LinkList	L;
	L = new	LNode;
	L->next = NULL;
	while (1)
	{
		cover7();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://��Ƶͳ��
			system("CLS");
			l=input_LinkList(L);
			sort_linklist(L,l);
			outfile_LinkList(L, "OutFile2.txt", l);
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2116://���ʲ���
			system("CLS");
			cover12();
			findword_linklist();
			system("CLS");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2025:
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "���������������������룺" << endl;
			break;
		}
	}
}

int	shunxufind_list()//�������Ա�˳�����
{
	int	t;
	string	s;
	while (1)
	{
		cover3();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://����˳����˳�����
			system("CLS");
			shunxufind_sqlist();
			break;
		case	2116://���������˳�����
			system("CLS");
			shunxufind_linklist();
			break;
		case	2025://������һ��
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "���������������������룺" << endl;
			break;
		}
	}
}

int	zhebanfind_list()//�������Ա��۰����
{
	SqList	wu;
	wu.elem = new	Word[maxsize];
	string	s;
	int	t;
	input_sqlist(wu);
	qsort_sqlist(wu, 0, wu.len - 1);
	while (1)
	{
		cover6();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://��Ƶͳ��
			system("CLS");
			outfile_sqlist(wu, "OutFile3.txt");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2116://���ʲ���
			system("CLS");
			cover12();
			zhebanfind(wu);
			system("CLS");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2025://������һ��
			system("CLS");
			return 1;
		default:
			system("CLS");
			cout << "���������������������룺" << endl;
			break;
		}
	}
}

int	find_list()//�������Ա�Ĳ���
{
	string	s;
	int	t;
	while (1)
	{
		cover2();
		cin >> s;
		t = Hash(s);
		switch(t)
		{
		case	2209://�������Ա�˳�����
			system("CLS");
			shunxufind_list();
			break;
		case	2116://�������Ա��۰����
			system("CLS");
			zhebanfind_list();
			break;
		case	2025:
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "���������������������룺" << endl;
			break;
		}
	}
}

int	bst_find()//���ڶ����������Ĳ���
{
	BSTree Tree;
	Tree = NULL;
	input_bst(Tree);
	string	s;
	int	t;
	while (1)
	{
		cover8();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://��Ƶͳ��
			system("CLS");
			outfile_bst(Tree, "OutFile4.txt");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2116://���ʲ���
			system("CLS");
			cover12();
			bst_findword(Tree);
			system("CLS");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2025://������һ��
			system("CLS");
			return 1;
		default:
			system("CLS");
			cout << "���������������������룺" << endl;
			break;
		}
	}
}

int	open_address_hash()//���ڿ��ŵ�ַ����hash����
{
	HashTable	wu[maxsize];
	input_hash_openadd(wu);
	string	s;
	int	t;
	while (1)
	{
		cover10();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://��Ƶͳ��
			system("CLS");
			outfile_hash(wu, "OutFile5.txt");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2116://���ʲ���
			system("CLS");
			cover12();
			findword_hashadd(wu);
			system("CLS");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2025://������һ��
			system("CLS");
			return 1;
		default:
			system("CLS");
			cout << "���������������������룺" << endl;
			break;
		}
	}
}

int	hash_linklist()//��������ַ���Ĺ�ϣ����
{
	hash_LNode	HT;
	input_hash_linklist(HT);
	string	s;
	int	t;
	while (1)
	{
		cover11();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://��Ƶͳ��
			system("CLS");
			outfile_hash_linklist(HT, "OutFile6.txt");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2116://���ʲ���
			system("CLS");
			cover12();
			findword_hashlinklist(HT);
			system("CLS");
			cout << "��������������Ҫ���еĲ�����\n" << endl;
			break;
		case	2025://������һ��
			system("CLS");
			return 1;
		default:
			system("CLS");
			cout << "���������������������룺" << endl;
			break;
		}
	}
}

int	find_hash()//���ڹ�ϣ��Ĳ���
{
	string	s;
	int	t;
	while (1)
	{
		cover9();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://���ڿ��ŵ�ַ���Ĺ�ϣ����
			system("CLS");
			open_address_hash();
			break;
		case	2116://��������ַ���Ĺ�ϣ����
			system("CLS");
			hash_linklist();
			break;
		case	2025:
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "����������������������\n";
		}
	}
}

int	main()
{
	string s;
	int  t;
	while (1)
	{
		cover1();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://�������Ա����
			system("CLS");
			find_list();
			break;
		case	2116://���ڶ����������Ĳ���
			system("CLS");
			bst_find();
			break;
		case	2025://���ڹ�ϣ��Ĳ���
			system("CLS");
			find_hash();
			system("CLS");
			break;
		case	1936:
			cout << "��ӭ�ٴ�ʹ�á�~ \n";
			return	0;
		default:
			system("CLS");
			cout << "���������������������룺" << endl;
			break;
		}
	}
}