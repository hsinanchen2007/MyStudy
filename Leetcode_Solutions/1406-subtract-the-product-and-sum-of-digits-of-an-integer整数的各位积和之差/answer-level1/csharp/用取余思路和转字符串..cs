### 解题思路
用取余方法来完成 44ms,14mb.
用字符串来完成 48ms,14.1mb.
.



### 代码

```csharp
public class Solution {
    public int SubtractProductAndSum(int nums) {
      return GetNumsJi(nums) - GetNumsSum(nums);
    }
      public int GetNumsSum(int n)
        {
            int sum = 0;
            while (n > 0)
            {
                sum += n % 10;
                n /= 10;
            }
            return sum;
        }

        public int GetNumsJi(int n)
        {
            int ji = 1;
            while (n>0)
            {
                ji *= n % 10;
                n /= 10;
            }
            return ji;
        }

  
}
`````````````````````````````````````````````````````````````````````````

 public class Solution
    {

        public int GetNumsCha(int nums)
        {
           return  GetNumsJi(nums) - GetNumsSum(nums);
        }



        public int GetNumsSum(int nums)
        {
            string s = nums.ToString();
            int sum = 0;
            foreach (var i in s)
            {               
                sum += Convert.ToInt32(i.ToString());                
            }
            return sum;
        }

        public int GetNumsJi(int nums)
        {
            string s = nums.ToString();
            int ji = 1;
            foreach (var i in s)
            {
                ji *= Convert.ToInt32(i.ToString());
            }
            return ji;
        }
    }

