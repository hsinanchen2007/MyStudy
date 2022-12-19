### 解题思路
一般来说数组和链表相关的操作都会用额外指针的方式去解决，这一题也不例外。

### 代码

```csharp
public void MoveZeroes(int[] nums)
        {
            int currentIndex = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] != 0)
                {
                    nums[currentIndex] = nums[i];
                    currentIndex++;
                }
            }

            for(;currentIndex < nums.Length; currentIndex++)
            {
                nums[currentIndex] = 0;
            }
        }
```