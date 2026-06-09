### 解题思路
一开始读题是懵逼状态，后来看了大家的题解，才知道是要干啥
1.循环数组
2.循环奇数位次数
3.返回偶数位的值
### 代码

```csharp
public class Solution {
    public int[] DecompressRLElist(int[] nums) {
        List<int> deComint=new List<int>();
        for(int i=0;i<nums.Length;i+=2) //相邻两个元素，所以步长为2
        {
            for(int j=0;j<nums[i];j++) //奇数位的值，是要循环的次数
            {
                deComint.Add(nums[i+1]); //偶数位的值，是要解压的值
            }
        }
        return deComint.ToArray();
    }
}

```