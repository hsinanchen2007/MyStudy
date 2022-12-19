C++解法，把每个节点按照{值, 所属列表编号}的结构存储，合并所有节点并升序排序后采用双指针求解。
这里用了一个数组来存储当前区间包含的各列表元素个数，列表数为0或1的情况直接返回，列表数大于1的情况每次循环经历如下步骤：
1. 右指针移动到恰好涵盖所有列表的最左位置（即在当前节点前，区间仅涵盖num-1个列表；算上此节点涵盖全部列表）
2. 左指针移动到恰好涵盖所有列表的最右位置（即在当前节点后，区间仅涵盖num-1个列表；算上此节点涵盖全部列表）
3. 用当前的左右指针和最终答案的左右指针比较并替换
4. 左指针移动到恰好涵盖num-1个列表的最右位置（即在当前节点后，区间仅涵盖num-2个列表；算上此节点涵盖num-1个列表）

```
class Solution {
public:
    struct node{
        int val, area;                                          //节点值和节点所属列表编号
    };
    
    static bool comp(node n1, node n2) {
        return (n1.val < n2.val) || (n1.val == n2.val && n1.area < n2.area);
    }
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int num = nums.size();
        int counts[num] = {0};                                  // 当前区间包含的各列表元素个数
        vector<int> ans;
        vector<node> nodes;                                     // 将所有节点合并排序后的数组
        // 处理列表不足两个的情况
        if(!num)    return ans;
        if(num == 1){
            ans.push_back(nums[0][0]);
            ans.push_back(nums[0][0]);
            return ans;
        }
        for(int i = 0; i < num; i++){
            for(int j = 0; j < nums[i].size(); j++){
                node curr = {nums[i][j], i};
                nodes.push_back(curr);
            }
        }
        sort(nodes.begin(), nodes.end(), comp);
        
        int nodenum = nodes.size(), l = 0, r = -1, flag = 0;    // 左右指针和当前区间涵盖的列表数
        int ansl = 0, ansr = nodenum - 1;                       // 最终左右指针
        while(r < nodenum - 1){
            // 右指针移动到恰好涵盖所有列表的最左位置
            while(r < nodenum - 1 && flag < num){
                r++;
                if(!counts[nodes[r].area])      flag++;
                counts[nodes[r].area]++;
            }
            // 左指针移动到恰好涵盖所有列表的最右位置
            while(l < r && counts[nodes[l].area] > 1){
                counts[nodes[l].area]--;
                l++;
            }
            // 和当前答案比较并替换
            if(flag == num && nodes[r].val - nodes[l].val < nodes[ansr].val - nodes[ansl].val)
                ansl = l, ansr = r;
            // 左指针移动到恰好涵盖num-1个列表的最右位置
            while(l < r){
                if(counts[nodes[l].area]){
                    counts[nodes[l].area]--;
                    if(!counts[nodes[l].area]){
                        // 删除此节点后涵盖num-1个列表
                        if(flag == num)     flag--;
                        // 删除此节点后涵盖num-2个列表（停止点）
                        else{
                            counts[nodes[l].area]++;
                            break;
                        }
                    }
                }
                l++;
            }
        }
        ans.push_back(nodes[ansl].val);
        ans.push_back(nodes[ansr].val);
        return ans;
    }
};
```
