### 解题思路
![image.png](https://pic.leetcode-cn.com/16f1c78278e9aa088a3152cabaa8580ee06c128ee53e32381672cb8529500d47-image.png)

删除注释，是典型的控制类程序，状态机是该类问题的最优算法。

设置5种状态，其中2种归0，实际为3状态，即：0正常字符，1遇到字符'/'，2->0得到"//"，3得到"/*"，4块中遇到'*'，5->0块中遇到“*/”

问题的难点在于跨行的块，算法使用如下结构：
（1）以循环获取并处理source一行字符为基本结构
（2）一次循环处理source中的一行
（3）循环首尾插入处理逻辑，判断是否需要新生成一行结果

这样实现了结果字符串和source字符串的解耦

另外，吐槽一下这条用例：
["void func(int k) {", "// this function does nothing /*", "   k = k*2/4;", "   k = k/2;*/", "}"]

说好的“ 所以在行或块注释之外的/*总是开始新的注释。”？

用例太随意了吧


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char res_[100][200];
char *res[100];

//【算法思路】状态机。
char ** removeComments(char ** source, int sourceSize, int* returnSize){
	if(sourceSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}

	int rsize = 0;

	//0表示正常，1表示/，2(0)表示//，3表示/*，4表示*，5(0)表示*/
	int dp = 0;

	int sid = 0;

	char *tres;
	//记录有效字符的位置
	bool vflag = true;
	int vid;

	while(sid < sourceSize)
	{
		//如果已经处理完成则进行结果整理，否则，继续处理块中数据
		if(dp == 0 || dp == 1)
		{
			//新启用一行结果
			tres = res_[rsize];
			vid = 0;
		}
		
		char *cur = source[sid];
		sid++;

		int tlen = strlen(cur);

		int cid = 0;
		while(cid < tlen)
		{
            if(dp == 0 || dp == 1)
            {
                vflag = true;
            }

			if(cur[cid] == '/')
			{
				if(dp == 0)
				{
					dp = 1;
				}
				else if(dp == 1)
				{
					//确认为//，当前行处理完毕
					dp = 0;
					//回退掉上一个/
					vid -= 1;
					break;
				}
				else if(dp == 4)
				{
					//块结束，和之前保存的cur行进行合并
					dp = 0;
                    //稍后开启输出
                    //vflag = true;
				}
			}
			else if(cur[cid] == '*')
			{
				if(dp == 1)
				{
					//确认为/*
					dp = 3;
					//回退掉上一个/
					vid -= 1;
                    //立即停止输入
                    vflag = false;
				}
				else if(dp == 3)
				{
					//准备块结束
					dp = 4;
				}
			}
			else
			{
				if(dp == 1)
				{
					//并非注释
					dp = 0;
				}

				if(dp == 4)
				{
					//并非块结束
					dp = 3;
				}
			}

			if(vflag == true)
			{
				tres[vid] = cur[cid];
				vid++;
			}
			cid++;
/*
            printf("[dp = %d]", dp);
            for(int i = 0;  i < vid; i++)
            {
                printf("%c", tres[i]);
            }
            printf("\n", dp);
*/
		}

        //printf("---------------\n");

		//如果已经处理完成则进行结果整理，否则，继续处理块中数据
		if(dp == 0 || dp == 1)
		{
			tres[vid] = '\0';
			res[rsize] = tres;

			//注意去除空行
			if(strlen(tres) > 0)
			{
				rsize++;
			}
		}
	}

	*returnSize = rsize;
	return res;
}

```