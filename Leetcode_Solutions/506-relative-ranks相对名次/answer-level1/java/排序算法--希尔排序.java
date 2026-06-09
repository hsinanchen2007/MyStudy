### 解题思路
新建了一个数组，用来储存原数组各个位置的下标。
然后给原数组排序的同时，给这个下标数组进行同样的排序。
然后再新建一个字符串的结果数组，
依据下标数组依次填入数据就可以了

### 代码

```java
class Solution {
    public String[] findRelativeRanks(int[] nums) {
        int [] count = new int[nums.length];
        for (int x=0;x<count.length;x++){
            count[x]=x;
        }

        int n=nums.length/2;
        while (n>0){
            for (int x=n;x<2*n;x++){
                for (int y=x;y<nums.length;y+=n){
                    int val=nums[y];
                    int m=count[y];
                    int index =y-n;

                    while (index>=0&&nums[index]<val){
                        nums[index+n]=nums[index];
                        count[index+n]=count[index];
                        index-=n;
                    }
                    nums[index+n]=val;
                    count[index+n]=m;


                }
            }
            n/=2;
        }
        String[]result=new String[nums.length];
        String s1="Gold Medal";
        String s2="Silver Medal";
        String s3="Bronze Medal";
        for (int x=0;x<count.length;x++){
            if (x==0){
                result[count[x]]=s1;
                continue;
            }
            if (x==1){
                result[count[x]]=s2;
                continue;
            }
            if(x==2){
                result[count[x]]=s3;
                continue;
            }
            result[count[x]]=x+1+"";

        }
        return result;
    }
}
```