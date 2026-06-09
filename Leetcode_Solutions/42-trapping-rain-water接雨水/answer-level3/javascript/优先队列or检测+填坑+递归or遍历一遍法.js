### 优先队列法
> 此为通过对407接雨水-ii中题解的学习后总结得到的一种方法：
- 将边界加入最小堆，同时将两个点设置为已访问
- 取根节点（最小值）访问它的``周边``如果有``凹陷``则进行``就近填平``，加入周边的点且值为填平后的值，周边加入时将其设置为已经访问
- 获取累加值
```javascript
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

const trap=height=>{
    let res=0,h=new Heap(),dir=[-1,1],visited=new Map();
    h.insert({'pos':0,'val':height[0]},'val');
    h.insert({'pos':height.length-1,'val':height[height.length-1]},'val');
    visited.set(0,true);
    visited.set(height.length-1,true);
    while(h.data.length){
        let temp=h.deleting('val');
        for(let i=0;i<dir.length;i++){
            let newOne=temp.pos+dir[i];
            if(newOne>=0&&newOne<height.length&&!visited.has(newOne)){
                res+=Math.max(0,temp.val-height[newOne]);
                h.insert({'pos':newOne,'val':Math.max(height[newOne],temp.val)},'val');
                visited.set(newOne,true);
            }
        }
    }
    return res;
};
```

### 检测+填坑+递归
其实可以看作是暴力解的一种优化：主要是限制了不是每个元素都需要遍历去寻找它的max_left max_right。这种方法能准确定位到是哪个位置进行了填补，个人觉得比较简单易懂。
- 在外层循环中只有寻找是凹位置的元素，否则跳过
    + 向左寻找距离它最近的比它大的元素索引，限制条件是向左只要有比它小的就停止遍历 ``findLeft(arr,i)``
    + 向右寻找距离它最近的比它大的元素索引，限制条件是向右只要有比它小的就停止遍历``findRight(arr,i)``
    + 找到后`` let min=Math.min(arr[left],arr[right])``
    + 此时从left开始进行累加到right，凡是比min小的都加进res,同时进行``填坑``
    + 遍历的指针变为right-1,++后即从right再次开始遍历
- 在填坑操作中有可能只是填了小坑，尤其对于``[5,2,1,2,1,5]``这种情况，填完会变成``[5,2,2,2,2,5]``，因此需要判断填完坑的height和原数组是否一样
    + 若不一样需要进行递归操作 res+trap(height);
    + 若一样直接返回res
```javascript
    const trap = (arr)=>{
        let temp=arr.join(',');
        let len=arr.length;
        let res=0;
        for (let i=1;i<len-1;i++){
            if(arr[i-1]>=arr[i]&&arr[i+1]>=arr[i]){
                let left=findLeft(arr,i);
                let right=findRight(arr,i);
                console.info(left,right);
                let min=Math.min(arr[left],arr[right]);
                for(let j=left;j<=right;j++){
                    if(min-arr[j]>0){
                        res+=min-arr[j];
                        arr[j]=min;
                    }
                }
                i=right-1;
            }
        }
        if(arr.join(',')!==temp){
            return res+trap(arr);
        }else{
            return res;
        }
    };
    const findLeft=(arr,i)=>{
        let max=i;
        while(i>0){
            if (arr[i-1]>arr[max]){
                max=i-1;
                i--;
            }else{
                break;
            }
        }
        return max;
    };
    const findRight=(arr,i)=>{
        let max=i;
        while(i<arr.length-1){
            if(arr[i+1]>=arr[max]){
                max=i+1;
                i++
            }else{
                break;
            }
        }
        return max;
    };

```
### 遍历一次
- 时间复杂度:O(n)
```javascript
/**
 * 遍历所有元素（除了首尾）查找空缺
 * findVacancy 查找空缺
 * getSum 获取空缺处的降雨量总和
 */
const findVacancy=(arr,i)=>{
    let l=i,r=i,min=i;
    // find max
    for(let m=i-1;m>=0;m--){
        if(arr[m]>=arr[l]){
            l=m;
        }else break;
    }
    // 关键点在于向后查找
    // 确定最小元素的位置
    for(let n=i+1;n<arr.length;n++){
        if(arr[n]<=arr[min]){
            min=n;
        }else{
            break;
        }
    }
    r=min;
    // 向后查找是一件很困难的事情，有其对于[5,4,1,2],[5,2,1,2,1,5]这种情况
    // 因此如果有了比左侧最大值大的情况就应该退出
    for(let p=min+1;p<arr.length;p++){
        if(arr[p]>=arr[r]){
            r=p;
        }
        if(arr[p]>=arr[l]) break;
    }
    // console.info(min,r);
    if(min!==i&&min===r) return{l,'r':null};
    return {l,r};
};
const getSum=(arr,obj)=>{
    let {l,r}=obj,res=0;
    let min=Math.min(arr[l],arr[r]);
    // console.info('min==>',min,l,r);
    for(let i=l;i<=r;i++){
        if(min-arr[i]>0){
            res+=min-arr[i];
        }
    }
    return res;
};
const trap=height=>{
    let i=1,res=0;
    while(i<height.length-1)
    {
        // 这里我们判定中间凸出或者递增型的一定不适合去盛雨水
        let flag=(height[i-1]<height[i]&&height[i+1]<height[i])||(height[i-1]<=height[i]&&height[i+1]>height[i]);
        if(flag){
            i++;
        }else{
            let temp=findVacancy(height,i);
            // console.info('temp==>',temp);
            if(temp.r){
                res+=getSum(height,temp);
                i=temp.r;
            }else{
                break;
            }
        }
    }
    return res;
};
```