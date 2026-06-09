![image.png](https://pic.leetcode-cn.com/7c7506471b653b09769672b71f48d8c7d38596de3f32c12cd8138addba7888ee-image.png)

```
 vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> mat(n, vector<int>(n));
	    int start = 1;
	    int c = 0;//c表遍历的圈数
        while (1)
        {
            if(n%2 && start == n*n)//当n为奇数，n-2*c -1最后会为0，但是此时还剩下一个元素未填充
                mat[c][c] = start++;
            if (start > n*n)
                break;
            for (int i = 0; i < n -  2*c - 1; i++)//每遍历一圈，每行每列减少2
                mat[c][c + i] = start++;
            for (int i = 0; i < n -  2*c - 1; i++)
                mat[i + c][n - 1 - c] = start++;
            for (int i = 0; i < n -  2*c - 1; i++)
                mat[n - 1 - c][n - 1 - i - c] = start++;
            for (int i = 0; i < n -  2*c - 1; i++)
                mat[n - 1 - i - c][c] = start++;	
            c++;
        }
            return mat;
    }
```
