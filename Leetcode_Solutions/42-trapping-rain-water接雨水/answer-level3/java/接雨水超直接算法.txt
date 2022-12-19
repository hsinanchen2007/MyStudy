# 思路：
这个方法的思路就很直观。水往低处走，一个柱子往右走，如果下一个柱子更矮，则可以存水，如果更高，则存水结束，然后重新对高的柱子存水。
所以，只要找到最高的柱子，然后分别从左开始和从右开始来计算存水的量，就可以解决了。
时间复杂度**O(n),原地算法。**
这里的代码只能从低到高算存水，所以当没有找到更高的时候，要从右边向左边遍历。

# 代码：
```
class Solution {
    public int trap(int[] height) {
        int result=0;
        boolean e=false;
        for(int i=0;i<height.length;i++) {
            int j=i+1;
            int temp=0;
            e=false;
            if(height[i]==0) continue;
            while(j<height.length){
                if(height[j]<height[i]) {
                    temp+=height[i]-height[j];
                    j++;
                }
                else {
                    result+=temp;
                    e=true;
                    break;
                }
            }
            if(e){
                i=j-1;
            }
            else {
                for(int k=height.length-1;k>=i;k--){
                    int l=k-1;
                    int temp2=0;
                    boolean e2=false;
                    if(height[k]==0) continue;
                    while(l>=i){
                        if(height[l]<height[k]){
                            temp2+=height[k]-height[l];
                            l--;
                        }
                        else{
                            result+=temp2;
                            e2=true;
                            break;
                        }
                    }
                    if(e2) k=l+1;
                }
                break;
            }
        }
        return result;
    }
}
```
