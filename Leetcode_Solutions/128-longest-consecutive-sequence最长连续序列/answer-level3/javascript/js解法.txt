```
  let len = nums.length;
    let set = new Set();
    let i = 0;
    let res = 0;
    while (i < len) {          // 去重并将元素放入set集合
        set.add(nums[i]);
        i++;
    }
    for (let v of set) {
       if (!set.has(v - 1)) {
            let curr = v;
            let currLen = 1;
            while (set.has(++curr)) {
                set.delete(curr);          // 已经排查过的元素删除掉，避免重复遍历
                currLen++;
            }
            res = Math.max(res, currLen);
       }
    }
    return res;
```
