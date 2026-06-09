#A1：超出时间限制的暴力方法==
首先新建vector拷贝原数组，冒泡排序，再分别从头和尾比较原，新数组的值，记录第一个不同的数
```
for(int i = 0; i < sort.size(); i++){
            for(int j = i+1; j < sort.size(); j++){
                if(sort[i] > sort[j]){
                    int temp;
                    temp = sort[i];
                    sort[i] = sort[j];
                    sort[j] = temp;
                }
            }
        }
        int begin = 0;
        int end = 0;
        for(int i = 0; i < sort.size(); i++){
            if(sort[i] != nums[i]){
                begin = i;
                break;
            }
        }
        
        for(int i = sort.size()-1; i >= 0; i--){
            if(sort[i] != nums[i]){
                end = i;
                break;
            }
        }
        
        int length;
        if(end - begin > 0){
            length = end - begin + 1;
        }
        return length;
```
A2：分别从头和尾搜索，记录最远min,max位置
```
int max, min, begin, end;
        max = nums[0];
        min = nums[nums.size()-1];
        begin = 0;
        end = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= max){
                max = nums[i];
            }
            else{
                end = i;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] <= min){
                min = nums[i];
            }
            else{
                begin = i;
            }
        }
       
        int length;
        length = end - begin;
        if(length > 0){
            length += 1;
        }
```

