这道题没有仔细想，但是直接套线段树还是能快速得到答案，因为nlogn速度也是90+

1. 先将capital-profit对子按照capital升序排列
2. 建区间最大值线段树，叶子结点存最大值在的index
3. 以当前拥有的资本W为区间右断点，求左区间的profit最大值

```
class Solution {
public:
    vector<int> segTree;
    vector<pair<int,int>> capital_profit;
    int build(int left, int right, int idx){
        if(left==right){
            segTree[idx] = left;
            return left;
        }
        int mid = (left+right)/2;
        int leftmax = build(left, mid, idx*2+1);
        int rightmax = build(mid+1, right, idx*2+2);
        if(capital_profit[leftmax].second > capital_profit[rightmax].second)
            segTree[idx] = leftmax;
        else
            segTree[idx] = rightmax;
        return segTree[idx];
    }
    int rangeMax(int left, int right, int targetLeft, int targetRight, int idx){
        if(left==targetLeft && right==targetRight){
            return segTree[idx];
        }
        int mid = (left+right)/2;
        if(targetRight<=mid) return rangeMax(left, mid, targetLeft, targetRight, idx*2+1);
        if(targetLeft>mid)   return rangeMax(mid+1, right, targetLeft, targetRight, idx*2+2);
        int leftmax = rangeMax(left, mid, targetLeft, mid, idx*2+1);
        int rightmax = rangeMax(mid+1, right, mid+1, targetRight, idx*2+2);
        if(capital_profit[leftmax].second > capital_profit[rightmax].second)
            segTree[idx] = leftmax;
        else
            segTree[idx] = rightmax;
        return segTree[idx];
    }
    int update(int left, int right, int mod, int idx){
        if(left==right) return segTree[idx];
        int mid = (left+right)/2;
        int updateMax = 0;
        int anotherMax = 0;
        if(mod<=mid){
            updateMax = update(left, mid, mod, idx*2+1);
            anotherMax = segTree[idx*2+2];
        } else {
            anotherMax = segTree[idx*2+1];
            updateMax = update(mid+1, right, mod, idx*2+2);
        }
        if(capital_profit[anotherMax].second > capital_profit[updateMax].second)
            segTree[idx] = anotherMax;
        else
            segTree[idx] = updateMax;
        return segTree[idx];
    }

    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int len = Profits.size();
        capital_profit = vector<pair<int,int>>(len);
        for(int i=0; i<len; i++){
            capital_profit[i] = {Capital[i], Profits[i]};
        }
        sort(capital_profit.begin(), capital_profit.end());
        segTree = vector<int>(len*4);
        build(0, len-1, 0);
        int capital_profit_id = -1;
        while(k){
            while(capital_profit_id+1<len&&capital_profit[capital_profit_id+1].first<=W) capital_profit_id++;
            if(capital_profit_id==-1) break;
            int max_profit_id = rangeMax(0, len-1, 0, capital_profit_id, 0);
            if(capital_profit[max_profit_id].second==0) break;
            W += capital_profit[max_profit_id].second;
            capital_profit[max_profit_id].second = 0;
            update(0, len-1, max_profit_id, 0);
            k--;
        }
        return W;
    }
};
```
