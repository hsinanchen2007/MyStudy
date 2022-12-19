### 解题思路
mgj终于写出来了.我觉得放在简单太打击人了.开始写的时候采用的是先把数取出来,再加一,再放进去,然后发现问题是一直溢出.到long之后就顶不住了.然后发现直接在数组中操作比较简单.
判断最后一个数是不是9,如果是,就看它前面一个,直到前面一个不是9
最后一个数如果不是9,那就直接加一就好了

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
int len=digits.length-1;
        if (digits[len]==9)
        {
            while(digits[len]==9)
            {
                len--;
                if (len==-1)
                    break;
            }
            if (len==-1)
            {
                int []arr=new int[digits.length+1];
                arr[0]=1;
                for (int i=1;i<arr.length;i++)
                {
                    arr[i]=0;
                }
                return arr;
            }
            digits[len]+=1;
            for (int i=len+1;i<digits.length;i++)
            {

                digits[i]=0;
            }
            return digits;
        }
        else {
            digits[len]+=1;
            return digits;
        }
    }
}
```