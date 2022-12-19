```
 vector<int> subSort(vector<int>& array) {
        if (array.empty()) return {-1,-1};

        // 1.从左向右 寻找最大的max (默认第一个是最大index)
        // 2.记录max 如果后面有比这个小的 说明是逆序（记住当前ndex）
        int max = array[0];
        int length = array.size();
        int rightIndex = -1; 
        for (int i = 1; i<=length-1; i++) {
            int v = array[i];
            if (v >= max) {
                max = v;
            }else {
                rightIndex = i;
            }
        }

        if (rightIndex == -1) return {-1,-1};

        // 这里没必要合并到上面 逻辑清晰些，，性能一样
        // 3.从右向左和上面完全一样(修改运算逻辑)
        int min = array[length-1]; 
        int leftIndex = -1; 
        for (int i = length-2; i >= 0; --i) {
            int v = array[i];
            if (v <= min) {
                min = v;
            }else {
                leftIndex = i;
            }
        }
        
        return {leftIndex,rightIndex};
    }
```
