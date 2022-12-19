**思路：** 没啥说的都在代码里，多用测试用例修正自己的代码。
```
public IList<IList<int>> Generate(int numRows)
        {
            IList<IList<int>> result = new List<IList<int>>();

            for (int i = 0; i < numRows; i++)
            {
                var list = new List<int>(i + 1);
                for (int j = 0; j < i + 1; j++)
                {
                    int element;
                    if (i == 0 || j == 0 || j == i)
                    {
                        element = 1;
                    }
                    else
                    {
                        element = result[i - 1][j - 1] + result[i - 1][j];
                    }

                    list.Add(element);
                }

                result.Add(list);
            }

            return result;
        }
```
