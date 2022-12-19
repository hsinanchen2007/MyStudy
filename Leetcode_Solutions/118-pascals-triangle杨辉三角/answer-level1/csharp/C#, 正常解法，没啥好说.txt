```
/*
 * @lc app=leetcode.cn id=118 lang=csharp
 *
 * [118] 杨辉三角
 */
public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        if(numRows == 0)
        {
            return new List<IList<int>>();
        }

        var yangHuiList = new List<IList<int>>();
        for(int i = 0; i < numRows; i++)
        {
            yangHuiList.Add(new List<int>());
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i)
                {
                    yangHuiList[i].Add(1);
                }
                else
                {
                    yangHuiList[i].Add((yangHuiList[i - 1][j - 1] + yangHuiList[i - 1][j]));
                }
            }
        }

        return yangHuiList;
    }
}


```
