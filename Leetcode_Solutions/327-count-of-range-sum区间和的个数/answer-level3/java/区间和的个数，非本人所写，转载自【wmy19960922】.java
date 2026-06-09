### 解题思路
此处撰写解题思路

### 代码

```java
//非本人所写，来自wmy19960922
class Solution {
public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long[] sum = new long[n+1];
        for(int i=0;i<n;i++) {
            sum[i+1] = sum[i]+nums[i];//sum[i+1]表示从nums[0]加到nums[i]的和
        }
        Set<Long> set = new TreeSet<>();
        for(Long i:sum) {
            set.add(i);
            set.add(i+lower);
            set.add(i+upper);
        }
        Map<Long,Integer> map = new HashMap<>();
        int count=0;
        for(Long i:set) {
            map.put(i,++count);
        }
        biTree bt = new biTree(count);
        int ans = 0;
        for(int i =n;i>=0;i--) {
            
            int ll=bt.getNum(map.get(sum[i]+lower)-1); //这里面和值比那个小的的个数
            int rr = bt.getNum(map.get(sum[i]+upper)); //这里面和值比那个小的的个数
            ans+=(rr-ll);//目前已经存进去的肯定都是长度比当前大的
             bt.update(map.get(sum[i]));  
        }
        return ans;
    }
    public class biTree {    //中根序遍历!!!!!!!!!
        int[] C;
        int length;
        public biTree(int n) {
            C = new int[n+1];//保证最后一个是C[n]
            length = n;
        }
        public void update(int i) {
            while(i<=length) {
                C[i]++;                          //树状数组，只是为了简便计算？
                i+=(i&(-i));//返回 i  的二进制数最低位为１的权值
            }
        }
        public int getNum(int i) {
            int sum=0;
                while(i>=1) {
                    sum+=C[i];
                    i-=(i&(-i));
                }
            return sum;
        }
        
    }
}
```