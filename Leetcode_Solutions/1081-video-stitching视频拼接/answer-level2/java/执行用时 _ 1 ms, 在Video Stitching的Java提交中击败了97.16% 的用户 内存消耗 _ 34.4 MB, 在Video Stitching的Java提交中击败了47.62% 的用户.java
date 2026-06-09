成功
显示详情 
执行用时 : 1 ms, 在Video Stitching的Java提交中击败了97.16% 的用户
内存消耗 : 34.4 MB, 在Video Stitching的Java提交中击败了47.62% 的用户

```
class Solution {
    int res;
    int recu;
    public int videoStitching(int[][] clips, int T) {
        int[] qualified = new int[clips.length];

        submatch(clips, qualified, 0, T);
        
        return res;
    }
    
    public void submatch(int[][] clips, int[] qualified, int start, int end){
        recu++;
        
        boolean q=false;
        int s=-1;
        int maxs=start;
        int e=-1;
        int mine=end;
        for(int i=0; i<clips.length; i++){
            if(qualified[i]==0){
                q=true;
                 if(clips[i][0]<=start){
                     if(s==-1){
                         
                         s=i;
                         maxs=clips[i][1];
                         
                     }else if(clips[i][1]>maxs){
                          s=i;
                         maxs=clips[i][1];
                     }
                     qualified[i]=1;
                     if(maxs>=end){
                         res++;
                    return;
                     }
                 }
                
                 if(clips[i][1]>=end){
                     if(e==-1){
                            
                         e=i;
                         mine=clips[i][0];
                         
                     }else if(clips[i][0]<mine){
                            e=i;
                         mine=clips[i][0];
                     } 
                     qualified[i]=1;
                     if(mine<=start){
                         res++;
                         return;
                     }
                 }
                
                
            }
           
        }
        res=res+2;
        if(s==-1||e==-1){
            res=-1;
            return;
        }
        if(maxs<mine){
            if(recu>(clips.length>>1)){
                res=-1;
                return;
            }
             submatch(clips, qualified, maxs, mine);
        }else{
            if(clips[s][0]<=clips[e][0]&&clips[s][1]>=clips[e][1]
              ||clips[s][0]>=clips[e][0]&&clips[s][1]<=clips[e][1])res--;
        }
       
    }
}
```