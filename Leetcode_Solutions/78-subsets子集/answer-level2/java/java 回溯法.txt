### 解题思路
![image.png](https://pic.leetcode-cn.com/8bc4fbf2fa0287934394d4f63e535a66a563e06157f0c7a44f35bfda013ec91c-image.png)


### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        
        re.add(new ArrayList());
        trace(nums,0,new ArrayList<Integer>());
        return re;
    }

    List<List<Integer>> re=new ArrayList();

    public void trace(int[] nums,int n,List<Integer> cur){
        for(int i=n;i<nums.length;i++){
            cur.add(nums[i]);
            List t=new ArrayList();
            t.addAll(cur);
            re.add(t);
            trace(nums,i+1,cur);
            cur.remove(cur.size()-1);
        }
    }
}
```