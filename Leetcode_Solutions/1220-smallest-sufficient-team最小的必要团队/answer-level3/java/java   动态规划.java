### 解题思路
变相的背包问题

使用二进制来保存状态

举个例子，假设总共4种技能，3个人，技能情况为[1-1-0-0 , 0-0-1-1 , 1-1-1-1 ]
初始状态为0-0-0-0, （以下全部是二进制表示）
第一个人到来，0-0-0-0 || 1-1-0-0 = 1-1-0-0    dp[1100] = Math.min(dp[1100],dp[0000]+1) = 1;
第二个人到来，1-1-0-0 || 0-0-1-1 = 1-1-1-1    dp[1111] = Math.min(dp[1111],dp[1100]+1) = 2;
第三个人到来，0-0-0-0 || 1-1-1-1 = 1-1-1-1    dp[1111] = Math.min(dp[1111],dp[0000]+1) = 1;
所以最终使用最少的人为1个

思路是这个样子，具体的见代码
### 代码

```java
class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int len = req_skills.length;
        int length = (int)Math.pow(2,len);
        List<Integer>[] dp = new ArrayList[length];
        
        Map<String,Integer> map = new HashMap<>();
        //将技能对应二进制的位数
        for(int i=0 ; i<req_skills.length ; i++){
            map.put(req_skills[i],i);
        }
        dp[0] = new ArrayList<>();
        for(int i=0 ; i<people.size() ; i++){
            List<String> skills = people.get(i);
            List<Integer> list = new ArrayList<>();
            //当前人的技能的二进制位
            for(int j=0 ; j<skills.size() ; j++){
                list.add(map.get(skills.get(j)));
            }
            for(int j=length-1 ; j>=0 ; j--){
                if(dp[j]!=null){//说明这个状态是可达的
                    int num = j;
                    //状态叠加，加入当前人的技能
                    for(int k=0 ; k<list.size() ; k++){
                        num |= 1<<list.get(k);
                    }
                    if(dp[num]==null || dp[num].size()>dp[j].size()+1){
                        dp[num] = new ArrayList<>(dp[j]);
                        dp[num].add(i);
                    }
                }
            }
        }
        List<Integer> last = dp[length-1];
        int[] res = new int[last.size()];
        for(int i=0 ; i<last.size() ; i++){
            res[i] = last.get(i);
        }
        return res;
    }
}
```