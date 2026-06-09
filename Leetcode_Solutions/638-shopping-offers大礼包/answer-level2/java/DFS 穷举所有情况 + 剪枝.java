大家笑笑就好，写的比较复杂，但是逻辑不复杂，就是个穷举。
```
class Solution {
    
    List<Integer> price;
        
    List<List<Integer>> special;
    
    int min = 0;
    
     // 标记遍历到的礼包序号 
    int order = 0;
    
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        this.price = price;
        this.special = special;
        // 最保守的策略
        int res = 0;
        for(int i=0; i<price.size();i++){
            res += price.get(i) * needs.get(i);
        }
        this.min = res;
        dfs(0,needs);
        return min;
    }
    
    void dfs(int res, List<Integer> needs){
        if(isEmpty(needs)){
            min = Math.min(res , min);
            return;
        }
        if(order == special.size()){
            for(int i=0; i<price.size();i++){
                res += price.get(i) * needs.get(i);
            }
            min = Math.min(res , min);
            return;
        }
        boolean flag = true;
        // 判断是否可以买该礼包
        for(int i = 0; i<needs.size(); ++i){
            if(special.get(order).get(i) <= needs.get(i)){
                
            }else{
                flag = false;
                break;
            }
        }
        int oldRes = res;
        List<Integer> oldNeeds = new ArrayList<>();
        if(flag){
            for(int i : needs){
                oldNeeds.add(i);
            }
            res += special.get(order).get(needs.size());
            // 剪枝
            if(res < min){
                for(int i = 0; i<needs.size(); ++i){
                    needs.set(i,needs.get(i)-special.get(order).get(i));
                }
                dfs(res,needs);
            }
        }
        order++;
        if(flag){
            dfs(oldRes,oldNeeds);
        }else{
            dfs(oldRes,needs);
        }
        order--;
    }
    
    boolean isEmpty(List<Integer> needs){
        for(int i = 0; i < needs.size(); ++i){
            if(needs.get(i)!=0){
                return false;
            }
        }
        return true;
    }
}
```