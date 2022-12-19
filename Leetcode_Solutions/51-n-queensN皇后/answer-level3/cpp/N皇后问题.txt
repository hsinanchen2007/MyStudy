### 解题思路
本题是递归枚举，即回溯法的典型运用，能最大程度上减少枚举次数
（如果直接枚举所有皇后的排列情况再判断，则需要枚举C（n,n^2）次）

从题目易知，每行每列每条对角线都恰有一个皇后，因此可以直接按行进行枚举，
这样每次无需检查行是否冲突，故检查数组visited只需要检查列冲突和对角线冲突
此时最简单的思路是直接模拟一个二维bool棋盘数组，位置值为1即为皇后站位，这样在最后打印的时候
也可以利用该数组，一举两得；只是这样空间复杂度为O(n^2)，n过大会造成空间浪费；

因此此处我采用的是直接分别对列、主对角线、副对角线进行检查（即visited[3][]），
因为列有n列，主对角线和副对角线各有2n-1条，因此用二维数组visited[3][2n-1]即可；
只不过这样就得再额外申请一个一维int数组Line用来存储每行的列信息，但综合来看，空间复杂度仍降为O(n)，节省不少；

每层递归的情况就更加清楚了：
  当行数cur==n时，说明递归结束，可以生成一个对应的解method了；
  否则，即对该行进行枚举，检查该行的所有位置的可行性，对可行解进行下一层递归，否则什么也不做（即回溯到上层递归）

Notice：回溯法一般都会申请一个全局检查数组visited，以判断是否已经访问过相应位置，从而避免情况重复甚至死循环，
但是一定要注意的是，每次回溯前一定要将往下层递归时修改过的检查数组改回来，不然回溯之后枚举条件不对等；


### 代码

```cpp
class Solution {
public:
     bool* visited[3]; // visited[0][] for every column, visited[1][] for every \, visited[2][] for every /
     int* Line; // Line[i] for the column that the Queen standing in Line i 
     vector<vector<string>> methods; // all the methods for NQueens

     // print the line
     string printline(int col, int n)
     {
	      string s;
	      for (int i = 0; i < n; i++)
	        {
		          if (i == col)
			         s.push_back('Q');
		          else s.push_back('.');
	        }
	       return s;
      }

      // recursion func for every method
      void getQueen(int cur,int n)
      {
	      // recursion end, found one method
	      if (cur == n)
	      {
		     vector<string> method;
		     for (int i = 0; i < n; i++)
		     {
			     string temp = printline(Line[i], n);
			     method.push_back(temp);
		     }
		         methods.push_back(method);
	      }
	      // recurse to next line if found one place for this line
	      else for(int i=0;i<n;i++)
	      {
		      if (!visited[0][i] && !visited[1][i - cur + n - 1] && !visited[2][i + cur])
		      {
			     Line[cur] = i;
			     // modify the visited[][]
			     visited[0][i] = visited[1][i - cur + n - 1] = visited[2][i + cur] = true;
			     // recurse to next line
			     getQueen(cur + 1, n);
			     // restore the visited[][]
			     visited[0][i] = visited[1][i - cur + n - 1] = visited[2][i + cur] = false;
		      }
	       }
        }

    vector<vector<string>> solveNQueens(int n) {
        // initialize visited[3][]
	    for (int i = 0; i < 3; i++)
	    {
		    visited[i] = new bool[2 * n - 1];
		    for (int j = 0; j < 2 * n - 1; j++)
			   visited[i][j] = false;
	    }
	    // initialize Line[]
	    Line = new int[n];
        // recurse from beginning
        getQueen(0,n);

	    delete[] Line;
	    for (int i = 0; i < 3; i++)
		delete[] visited[i];

        return methods;
    }
};
```