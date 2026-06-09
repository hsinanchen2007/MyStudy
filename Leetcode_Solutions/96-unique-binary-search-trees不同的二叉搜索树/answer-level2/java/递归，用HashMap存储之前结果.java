执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
9.22%
的用户
内存消耗 :
33.8 MB
, 在所有 Java 提交中击败了
9.48%
的用户
```
class Solution {
    Map<Integer,Integer> map = new HashMap<>();
    public int numTrees(int n) {
        if(n==0)return 0;
        return get(1,n);
    }
    private int get(int s,int e){
        if(s>=e)return 1;
         
         Integer key = e-s;
        if( ( map.get(key))!=null){
            return map.get(key);
        }
        int sum=0;
        for(int i=s; i<=e; i++){
            int left = get(s,i-1);
            int right = get(i+1,e);
            sum+=left*right;
        }
        map.put(key,sum);
        return sum;
    }
}
```
