c# 题解  dfs 加回溯
```
public class SolveNQueen
    {
        //深度优先搜索
        //列是colum 行是row  行是横着的 “行”是横着的两个杠  “列”右侧竖着的两个杠
        List<string> GetString(List<int> cols)
        {
            List<string> res = new List<string>();
            for (int i = 0; i < cols.Count; i++)
            {
                StringBuilder str = new StringBuilder();
                for (int j = 0; j < cols.Count; j++)
                {
                    if (j == cols[i])
                    {
                        str.Append("Q");
                    }
                    else
                    {
                        str.Append(".");
                    }
                }
                res.Add(str.ToString());
            }
            return res;
        }
        //同行 同列 对角线
        bool IsValid(List<int> cols, int colum)
        {
            int l = cols.Count;
            for (int rowIndex = 0; rowIndex < cols.Count; rowIndex++)
            {
                //同行不判断 否则没结果
//                 if (colum == i)
//                 {
//                     return false;
//                 }
                int v = cols[rowIndex];
                if (v == colum)
                {
                    return false;
                }
                if (rowIndex + v == l + colum)
                {
                    return false;
                }
                if (rowIndex - v == l - colum)
                {
                    return false;
                }
            }
            return true;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="result"></param>
        /// <param name="cols">cols的索引是行数 值是列数  保存第n行的第几列是皇后</param>
        /// <param name="n"></param>
        void Search(List<IList<string>> result, List<int> cols, int n)
        {
            if (cols.Count == n)
            {
                result.Add(GetString(cols));
                return;
            }
            //判断一行的每一个元素
            for (int colIndex = 0; colIndex < n; colIndex++)
            {
                if (!IsValid(cols, colIndex))
                {
                    continue;
                }
                cols.Add(colIndex);
                Search(result, cols, n);
                //如果当前格子 不能放置n个皇后 则移除当前格子 回到上一行 判断下一个格子 
                cols.RemoveAt(cols.Count - 1);
            }

        }
        public IList<IList<string>> SolveNQueens(int n)
        {
            List<IList<string>> result = new List<IList<string>>();
            if (n == 0)
            {
                return result;
            }
            Search(result, new List<int>(), n);
            return result;

        }
    }
```
