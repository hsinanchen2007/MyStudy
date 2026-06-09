### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public IList<int> TransformArray(int[] arr) {
                bool flag = true;

                List<int> _list = arr.ToList();
                while (flag)
                {
                    int change = 0;
                    for (int i = 1; i < arr.Length - 1; i++)
                    {
                        int temp = arr[i];
                        if (temp < arr[i - 1] && temp < arr[i + 1])
                        {
                            _list[i] = temp + 1;
                            change++;
                        }
                        else if (temp > arr[i - 1] && temp > arr[i + 1])
                        {
                            _list[i] = temp - 1;
                            change++;
                        }
                    }
                    arr = _list.ToArray();
                    if (change == 0)
                    {
                        break;
                    }

                }
                return _list;
    }
}
```