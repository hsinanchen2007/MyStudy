1：队列法（似乎不满足题意...）

执行用时 :28 ms, 在所有 C++ 提交中击败了91.39%的用户
内存消耗 :9.6 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        //队列法
        queue<int> temp;
        
        for(auto i:arr){
            
            temp.push(i);
            
            if(i==0)
                temp.push(0);
        }
        
        for(int i=0; i<arr.size(); i++){
            
            arr[i] = temp.front();
            
            temp.pop();
        }
    }
};
```

2: 迭代器法

执行用时 :48 ms, 在所有 C++ 提交中击败了58.68%的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        //迭代器法
        for(auto it=arr.begin(); it<arr.end(); it++){
            
            if(*it==0){
                
                arr.pop_back();
                arr.insert(it,1,0);
                it++;
            }
        }
        

    }
};
```

3：逆向位移法

执行用时 :32 ms, 在所有 C++ 提交中击败了76.90%的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int count = 0;//记录0的数量
        
        for(auto i:arr){
            
            if(i==0)
                count++;
        }
        
        
        //逆向遍历数组 根据有效0（即数组的长度内允许复写的0）的个数平移各个数字
        for(int i=arr.size()-1; i>=0; i--){
            
            if(arr[i]==0){//如果当前指向的数字是0
                
                if(i+count>arr.size()-1){//如果不是有效0
                    
                    count--;//计数器减一
                    
                    if(i+count<=arr.size()-1){//虽然不是有效0（不允许复写） 但自身单独存在于新数组的末尾 则平移
                    
                        arr[i+count] = arr[i];
                    }
                }
                else{//如果是有效0 则平移+复写
                    
                    arr[i+count] = arr[i];
                    count--;
                    arr[i+count] = 0;
                }
  
            }
            else{//如果当前指向的不是0 则平移
                
                if(i+count<=arr.size()-1){
                    
                    arr[i+count] = arr[i];
                }
            }


        }

    }
};
```
