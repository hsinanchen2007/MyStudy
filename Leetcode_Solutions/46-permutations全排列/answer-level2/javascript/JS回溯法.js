### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 1. 回溯法;
 2. 注意JS中引用类型，浅拷贝和深拷贝;
 3. 被访问过的把 visited[i] = true;
 4. 递归结束或者找到结果之后，再把对应得 visited[i] = false;
 */
var permute = function(nums){
    let result = [];
    findSon([],[]);
    function findSon(visited,item){
        for(let j = 0; j < nums.length; j++){
            if(!visited[j]){
                visited[j] = true;
                item.push(nums[j]);
                if(item.length == nums.length){
                    let newItem = JSON.stringify(item);
                    newItem = JSON.parse(newItem)
                    result.push(newItem);
                    visited[j] = false;
                    item.pop();
                }else{
                    findSon(visited, item);
                    visited[j] = false;
                    item.pop();
                }
            }
        }
    }
    return result;
};
```