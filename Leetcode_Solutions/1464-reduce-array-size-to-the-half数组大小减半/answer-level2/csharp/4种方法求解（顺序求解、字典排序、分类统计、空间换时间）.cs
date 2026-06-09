## 解法一（顺序求解）
思路：最简单朴素的解法，首先进行元素统计，然后根据统计的结果按最大到小进行计算，不过当前解法C#会在数据大的情况下超时，而Python和GO不会，超时测试用例有6万多个元素，源码及超时用例如下：[https://www.zhenxiangsimple.com/files/tech/testCase20200202.txt](https://www.zhenxiangsimple.com/files/tech/testCase20200202.txt)
1. 统计元素个数
2. 按个数进行最大值累计，相当于冒泡排序

* 时间复杂度：O(n^2^)
* 空间复杂度：O(n)

```csharp
public class Solution {
    public int MinSetSize(int[] arr) {
        Dictionary<int,int> r = new Dictionary<int,int>();
        for(int i=0;i<arr.Length;i++)
        {//数据统计
            if(r.ContainsKey(arr[i]))
            {
                r[arr[i]] += 1;
            }
            else
            {
                r[arr[i]] = 1;
            }
        }
        int c = 0,ct = 0;
        while(c * 2<arr.Length)
        {//不需要全排序，只要满足条件即退出
            int mx = 0,idx = -1;
            foreach(var item in r)
            {//取数据最大值
                if(item.Value > mx)
                {
                    idx = item.Key;
                    mx = item.Value;
                }
            }
            r.Remove(idx);//最大值记录后退出循环
            c += mx;
            ct ++;
        }
        return ct;
    }
}
```
***
## 解法二（字典排序）
思路：基于解法一，先对结果进行排序，然后使用排序后的结果进行统计，按道理解法一更快，但可能.NET3.5对Dictionary的排序优化使得效率比自己查询更高。
* 时间复杂度：不算排序部分，O(n)
* 空间复杂度：O(n)
```csharp
public class Solution {
    public int MinSetSize(int[] arr) {
        Dictionary<int,int> r = new Dictionary<int,int>();
        for(int i=0;i<arr.Length;i++)
        {//数据统计
            if(r.ContainsKey(arr[i]))
            {
                r[arr[i]] += 1;
            }
            else
            {
                r[arr[i]] = 1;
            }
        }
        //排序
        var rOrder = from ro in r orderby ro.Value descending select ro;

        int c = 0,ct = 0;
        foreach(KeyValuePair<int,int> item in rOrder)
        {//累计
            c += item.Value;
            ct ++;
            if(c*2 >= arr.Length)
            {
                return ct;
            }            
        }
        return 0;//仅为编译
    }
}
```
***
## 解法三（分类统计）
思路：基于分类统计的思想，首先将元素进行统计，使用数组下标表示数组中元素个数，数组元素的值表示不同元素的个数，最后通过统计该数组下标即可。如果该元素为0，则表示不存在当前个数（数组下标对应的个数）的元素。
1. 统计数组中重复元素的个数放入数组r
2. 对数组中元素个数进行统计判断
3. 如果已经超出半数，则减去重复的个数（比如，r[2]=3，表示有两个相同元素的元素有3个，比如1,1,2,2,3,3,...，那么不需要3个元素全部累计，只需要满足超出半数即可，因此需要把多余的元素减去。
* 时间复杂度：O(n)
* 空间复杂度：O(n)
```csharp
public class Solution {
    public int MinSetSize(int[] arr) {
        int [] r = new int[arr.Length+1];//存储元素个数
        r[0] = arr.Length;
        Dictionary<int,int> d = new Dictionary<int,int>();
        foreach(int item in arr)
        {
            if(d.ContainsKey(item))
            {//已有元素时累计
                d[item]++;
            }
            else
            {//新元素增加
                d.Add(item,1);
            }

            r[d[item]]++;
            r[d[item]-1]--;
        }
        int c = 0,t = 0,idx = 0;
        for(int i=arr.Length;i>0;i--)
        {//从最大值到最小值进行统计
            if(r[i]>0)
            {
                c+= i*r[i];
                t+=r[i];
                idx = i;
            }
            if(c*2 >= arr.Length)
            {//如果超出限制，则减去重复的部分
                t -= (c*2 - arr.Length)/(2*i);
                break;
            }
        }
        return t;
    }
}
```
***
## 解法四（空间换时间）
思路：基于解法三的思路做一个变化，将值和索引做个交换，即使用一个大的空间，索引即为值本身，数组元素的值为该值对应的个数。缺点就是如果本身的值很大，就比较耗费资源，可以先便利一边找到最大值，也可以直接选择一个相对大的值，本次选择后者，一个相对大的值110000（开始选择10万，提示越界改为11万可以了）。
1. 统计值的个数
2. 对统计数组进行排序
3. 将排序结果从大到小进行求解
* 时间复杂度：O(n)，不算排序部分
* 空间复杂度：O(1)，虽然是1,但其实最大

```csharp
public class Solution {
    public int MinSetSize(int[] arr) {
        int[] r = new int[110000];
        foreach(int item in arr)
        {//元素个数统计
            r[item]++;
        }
        Array.Sort(r);//排序
        int c = 0,ct = 0;
        for(int i=r.Length-1;i>0;i--)
        {//个数计数
            c += r[i];
            ct ++;
            if(c*2 >= arr.Length)
            {
                return ct;
            }  
        }
        return 0;//仅为编译
    }
}
```

欢迎大佬们，随手关注VX公众号【[真相很简单](https://www.zhenxiangsimple.com/categories/tech/math/)】，拍砖指导，查看一题多解

![zhenxiangSimple](https://pic.leetcode-cn.com/f5cdcda21a37ab2959ff8c7fa75e174b326a0b126a27296ba28e906b7309dab1-zhenxiangSimple.jpg)