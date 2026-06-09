### 解题思路
把数组存入Map中，值当做key，出现次数当做value
遍历小map，判断key是否在另一个map出现，如果出现就按照较小的出现次数放入结果集
![微信截图_20200111155007.png](https://pic.leetcode-cn.com/950f969b91125bbc34beaf6a3dc57c2592e06dcff8b31032a0c0e49039c0725c-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200111155007.png)

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    const [map1,map2] = [new Map(),new Map()]
    const setValue = function(arr,map){
        arr.forEach(value =>{
            if(map.has(value)){
                map.set(value,map.get(value) + 1)
            }else{
                map.set(value,1)
            }
        })
    }
    const getIntersect = function(minMap,maxMap){
        const ret = [];
        [...minMap].forEach(([k,v]) =>{
            if(maxMap.has(k)){
                for(let i = 0;i<Math.min(v,maxMap.get(k));i++){
                    ret.push(k)
                }
            }
        })
        return ret
    }

    setValue(nums1,map1)
    setValue(nums2,map2)

    return map1.size > map2.size ? getIntersect(map2,map1):getIntersect(map1,map2)
};
```