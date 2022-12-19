### 解题思路
- 此题考察堆的应用：合并x个有序数组

### 代码
- 在js中创建堆这种数据结构
```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[][]}
 */
// 小根堆构建
function Heap(){
    this.data=[];
    this.build=build;
    this.insert=insert;
    this.deleting=deleting;
    this.print=print;
    this.heapSort=heapSort;
}
function insert(val,key){
    this.data.push(val);
    let idx=this.data.length-1;
    let fatherIdx=Math.floor((idx+1)/2)-1;
    // 注意核查的是父节点的索引值
    while(fatherIdx>=0){
        if(this.data[fatherIdx][key]>this.data[idx][key]){
            let temp=this.data[idx];
            this.data[idx]=this.data[fatherIdx];
            this.data[fatherIdx]=temp;
        }
        idx=fatherIdx;
        fatherIdx=Math.floor((idx+1)/2)-1;
    }
}
function deleting(key){
    let val=this.data[0];
    if(this.data.length===1){
        return this.data.pop();
    }
    this.data[0]=this.data.pop();
    // 重构最小堆
    let idx=0,len=this.data.length;
    while(idx<len){
        let left=idx*2+1,right=idx*2+2;
        let select=left;
        if(right<len){
            select=(this.data[left][key]>this.data[right][key])?right:left;
        }
        if (select<len&&this.data[select][key]<this.data[idx][key]){
            let temp=this.data[idx];
            this.data[idx]=this.data[select];
            this.data[select]=temp;
        }
        idx=select;
    }
    return val;
}
function build(arr,key){
    for(let i=0;i<arr.length;i++){
        this.insert(arr[i],key);
    }
}
function heapSort(){
    let res=[];
    while(this.data.length>0){
        res.push(this.deleting());
    }
    return res;
}
function print(){
    console.info('data==>',this.data);
}
```

- 将所有情况枚举放入堆中，此时时间复杂度就是``Nlogx``（其中：N是所有可能的对数，x是多少个有序数组）
```javascript
const kSmallestPairs = (nums1, nums2, k)=>{
    let h=new Heap(),res=[];
    for(let i=0;i<nums1.length;i++){
        for(let j=0;j<nums2.length;j++){
            h.insert({'arr':[nums1[i],nums2[j]],'sum':nums1[i]+nums2[j]},'sum');
        }
    }
    while(res.length<k&&h.data.length){
        res.push(h.deleting('sum').arr);
    }
    return res;
};
```
- 优化版：不需要枚举处所有情况加入到堆中：
```javascript
/**
 * 当我们学习了利用堆来合并k个有序数组之后，我们可以不枚举所有的情况而找到想要的k个组合
 * 注意组合为：[
 * [nums1[0]+nums2[0],nums1[0]+nums2[1],nums1[0]+nums2[2]],
 * [nums1[1]+nums2[0],nums1[1]+nums2[1],nums1[1]+nums2[2]],
 * [nums1[2]+nums2[0],nums1[2]+nums2[1],nums1[2]+nums2[2]],
 * ]的形式
 * @param nums1
 * @param nums2
 * @param k
 * @returns {[]}
 */
const kSmallestPairs=(nums1, nums2, k)=>{
    let h=new Heap(),res=[];
    if(nums2.length<1) return res;
    for(let i=0;i<nums1.length;i++){
        // 首先安排进来每个有序数组的第一个元素
        h.insert({'i':i,'j':0,'val':nums1[i]+nums2[0]},'val');
    }
    while(h.data.length&&res.length<k){
        let temp=h.deleting('val');
        res.push([nums1[temp.i],nums2[temp.j]]);
        if(nums2[temp.j+1]){
            h.insert({'i':temp.i,'j':temp.j+1,'val':nums1[temp.i]+nums2[temp.j+1]},'val');
        }
    }
    return res;

};

```
