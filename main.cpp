#include<iostream>
using namespace std;
#include<stack>

typedef struct chess
{
	int chess_row;
	int chess_column;
}chess;

void Print(int board[8][8])
{
	int i = 0; int j = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (board[i][j] == 0)
			{
				cout << ".";
			}
			else
			{
				cout << "#";
			}
		}
		cout << endl;
	}
}

int judge(int a, int b, int board[8][8])
{
	int i = 0; int j = 0; int sum = 0;
	sum = 0;
	for (i = 0; i < 8; i++)//判断行
	{
		sum += board[a][i];
		if (sum == 1)
		{
			return 0;
		}
	}
	sum = 0;
	for (i = 0; i < 8; i++)//判断列
	{
		sum += board[i][b];
		if (sum == 1)
		{
			return 0;
		}
	}
	sum = 0;//左斜线
	for (i = a, j = b; i < 8 && j < 8; i++, j++)//右下
	{
		sum += board[i][j];
	}
	for (i = a, j = b; i > -1 && j > -1; i--, j--)//左上
	{
		sum += board[i][j];
	}
	if (sum == 1)
	{
		return 0;
	}
	sum = 0;//右斜线
	for (i = a, j = b; i > -1 && j < 8; i--, j++)//左下
	{
		sum += board[i][j];
	}
	for (i = a, j = b; i <8 && j > -1; i++, j--)//右上
	{
		sum += board[i][j];
	}
	if (sum == 1)
	{
		return 0;
	}
	return 1;
}

int main()
{
	int row = 0; int column = 0;//第一个棋子的坐标
	int num = 0;
	int i = 0; int j = 0; //循环变量
	int k = 0;
	stack<chess> stk;//棋子栈
	chess tmp = { 0 };
	int board[8][8] = { 0 };
	for (column = 0; column < 8; column++)
	{
		while (stk.size() != 0)//初始化棋盘
		{
			stk.pop();
		}
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				board[i][j] = 0;
			}
		}
		board[row][column] = 1;
		tmp.chess_row = row;
		tmp.chess_column = column;
		stk.push(tmp);
		for (i = 1; i < 8; i++)//进行棋盘算法
		{
			k = 0;
			for (j = 0; j < 8; j++)
			{
				if (judge(i, j, board) != 0)//插入棋子
				{
					board[i][j] = 1;
					tmp.chess_row = i;
					tmp.chess_column = j;
					stk.push(tmp);
					k = 1;//标志位
				}
				if (stk.size() == 8 )//满足棋盘需求
				{
					k = 0;
					num++;
					Print(board);
					system("pause");
					do//进行递归
					{
						i =stk.top().chess_row;
						j = stk.top().chess_column;
						board[i][j] = 0;
						stk.pop();
						if (stk.size() == 0)//第一个棋子也无法满足需求，即不存在解
						{
							i = 8;
							break;
						}
					} while (j >= 7);
				}
				if (k == 0 && i != row && j == 7)//无法继续进行插入
				{
					do
					{
						i = stk.top().chess_row;
						j = stk.top().chess_column;
						board[i][j] = 0;
						stk.pop();
						if (stk.size() == 0)//第一个棋子也无法满足需求，即不存在解
						{
							i = 8;
							break;
						}
					} while (j >= 7);
				}
				if (i == 8)
				{
					break;
				}
			}
		}
	}
	cout << "八皇后问题共有:" << num << "种解法" << endl;
	system("pause");
	return 0;
}