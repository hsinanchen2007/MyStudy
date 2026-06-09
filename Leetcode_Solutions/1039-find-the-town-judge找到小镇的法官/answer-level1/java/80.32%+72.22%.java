思路：遍历查询出度与入度。满足入度为N-1且出度为0者即为所求。
```
class Solution {
    public static int findJudge(int N, int[][] trust) {
        int ans=-1;
        //首先遍历相信人,目标任务应不在此列
        int[] trust_people=new int[N];
        for(int i=0;i<=N-1;i++) {
        	trust_people[i]=0;
        }
        for(int i=0;i<=trust.length-1;i++) {
        	trust_people[trust[i][0]-1]++;
        }
        
        //随后针对每个候选人，观测是否其余人都相信他
        int[] be_trusted=new int[N];
        for(int i=0;i<=N-1;i++) {
        	be_trusted[i]=0;
        }
        for(int i=0;i<=trust.length-1;i++) {
        	be_trusted[trust[i][1]-1]++;
        }
        
        //遍历，找出符合条件的人
        for(int i=0;i<=N-1;i++) {
        	if(trust_people[i]==0&&be_trusted[i]==N-1) {
        		return i+1;
        	}
        }
        
        return ans;
    }
}
```
