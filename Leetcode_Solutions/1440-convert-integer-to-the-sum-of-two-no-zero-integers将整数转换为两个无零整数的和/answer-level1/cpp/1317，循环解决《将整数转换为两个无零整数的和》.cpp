### 解题思路
要把一个整数n拆分成两个不包含任何0的正整数a、b之和，那么最直观的思路：
1、对其中一个正整数a从1开始递增，那么另一个正整数b=n-a；
2、验证a和b是不是含0；
3、如果a、b都不含0，就返回[a,b]，否则递增a，递减b；
4、如果直到a=n-1都没有找到符合条件的值，就返回空列表。

注：这里进行验证一个正整数a是否包含0，使用的是遍历的方法。
1、设置a的标记为true（意思是符合条件）；
2、验证a对10的模是不是0（也就是验证a能否被10整除，能整除说明包含0），是0的话，将a的标记改为false，退出循环；
3、a整除10后重新赋值给a；
4、验证a是否等于0，等于0说明已经验证a符合条件，循环终止，否则，重复步骤2-4；
5、如果最后a的标记为true，说明a符合条件，为false说明不符合条件。

### 代码

```cpp
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        for(int i=1; i<n; i++)
        {
            int first = i;
            int second = n - i;
            bool first_flag = true;
            bool second_flag = true;
            for(first; first>0; first=first/10)
            {
                if (first % 10 == 0)
                {
                    first_flag = false;    
                    break;  
                };
            }

            for(second; second>0; second=second/10)
            {
                if(second % 10 == 0)
                {
                    second_flag = false;     
                    break;
                };
            }

            if (first_flag == true && second_flag == true)
            {
                result = {i, n - i};
                return result;
            }
        }
        return result;
    }
};
```