1. 先找到目标节点，在正常路径中的位置，如果为奇数行，则位置保持不变，如果为偶数行，则原始位置为pow(2,count-1)*3 - label - 1;
2. 先找到正常路径中从根节点到目标节点的路径。
3. 从正常路径中替换为之字路径的节点。
```
class Solution {
public:    
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        vector<int> bit;
        int num = label;
        int count = 0;
        int target = 0;
        
        while(num != 0){
            num >>= 1;
            count++;
        }
        if(count%2 == 0){
            target = pow(2,count-1)*3 - label - 1;
        }else{
            target = label;
        }
        while(target != 0){
            bit.push_back(target%2);
            target >>= 1;
        }
        reverse(bit.begin(),bit.end());
        int curr = 0;
        for(int i = 0;i < bit.size(); ++i){
            curr = curr*2 + bit[i];
            if(i%2){
                ans.push_back(pow(2,i)*3-curr-1);
            }else{
                ans.push_back(curr);
            }
        }
        
        return ans;
    }
```