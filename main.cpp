#include<iostream>
using namespace std;

int sum = 0;

void Print(int board[8][8],int num)
{
	int i = 0; int j = 0;
	cout << "NO." << num << ":  ";
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (board[i][j] == 1)
			{
				cout << j << "  ";
			}
		}
	}
	cout << endl;
	system("pause");
}

int judge(int a, int b, int board[8][8])
{
	int i = 0; int j = 0; int sum = 0;
	sum = 0;
	for (i = 0; i < 8; i++)//�ж���
	{
		sum += board[a][i];
		if (sum == 1)
		{
			return 0;
		}
	}
	sum = 0;
	for (i = 0; i < 8; i++)//�ж���
	{
		sum += board[i][b];
		if (sum == 1)
		{
			return 0;
		}
	}
	sum = 0;//��б��
	for (i = a, j = b; i < 8 && j < 8; i++, j++)//����
	{
		sum += board[i][j];
	}
	for (i = a, j = b; i > -1 && j > -1; i--, j--)//����
	{
		sum += board[i][j];
	}
	if (sum == 1)
	{
		return 0;
	}
	sum = 0;//��б��
	for (i = a, j = b; i > -1 && j < 8; i--, j++)//����
	{
		sum += board[i][j];
	}
	for (i = a, j = b; i <8 && j > -1; i++, j--)//����
	{
		sum += board[i][j];
	}
	if (sum == 1)
	{
		return 0;
	}
	return 1;
}

void Queenway(int num,int column,int board[8][8])//num:������column:����,board�� ���� ��ʵ������
{
	int j = 0;
	if (num == 8)
	{
		sum++;
		Print(board, sum);
		return;
	}
	for (j = 0; j < 8; j++)
	{
		if (judge(num, j, board) == 1)//�����������в���
		{
			board[num][j] = 1;
			Queenway(num + 1, 0,board);
		}
		board[num][j] = 0;
	}
}

int main()
{
	int column = 0; int i = 0; int j = 0;
	int board[8][8] = { 0 };
	for (column = 0; column < 8; column++)
	{
		for (i = 0; i < 8; i++)//��ʼ������
		{
			for (j = 0; j < 8; j++)
			{
				board[i][j] = 0;
			}
		}
		board[0][column] = 1;
		Queenway(1,0, board);
		
	}
	system("pause");
	return 0;
}