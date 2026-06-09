## 二分查找法
### 解题思路
- 找到最大值max和最小值min
- 计算mid值开始循环查找
    - 注意我们的max可以等于min，因为max min均为数组中的值
    - 如果比mid小的数目大于等于k，那么mid过大，max变成mid-1
        - 为什么要把等于k的情况加入呢，因为等于k的情况下，选取的mid是大于等于目标值的
    - 如果比mid大的数目小于k，那么mid过小，min变成mid+1
- 返回min值即为我们想要的
### code
```javascript
const kthSmallest = (matrix, k)=>{
    const count=(arr,tgt)=>{
        // let res=0;
        // for(let i=0;i<arr.length;i++){
        //     for(let j=0;j<arr[i].length;j++){
        //         if (arr[i][j]>tgt){
        //             break;
        //         }else{
        //             res++;
        //         }
        //     }
        // }
        // return res;
        // opt===>
        let res=0,right=arr[0].length;
        for(let i=0;i<arr.length;i++){
            for(let j=0;j<right;j++){
                if (arr[i][j]>tgt){
                    right=j;
                    break;
                }else{
                    res++;
                }
            }
        }
        return res;
    };
    let min=matrix[0][0],max=matrix[matrix.length-1][matrix[0].length-1];
    while(min<=max){
        let mid=Math.floor((min+max)/2);
        let cn=count(matrix,mid);
        if(cn>=k){
            // mid is too big even when cn===k
            max=mid-1;
        }else{
            min=mid+1;
        }
    }
    return min;
};
```
## 构建小根堆
### 解题思路
- 利用构建最小堆的方式将x个有序数组进行合并并且找到排序后的第k小元素。
- 不需要遍历所有元素。需要用对象存储元素所在数组的位置

### 代码

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
const kthSmallest = (matrix, k)=>{
    let h=new Heap(),res=[];
    for(let i=0;i<matrix.length;i++){
        h.insert({'i':i,'j':0,'val':matrix[i][0]},'val');
    }
    while(res.length<k&&h.data.length){
        // 添加元素
        let temp=h.deleting('val');
        res.push(temp.val);
        if(temp.j+1<matrix[temp.i].length){
            h.insert({'i':temp.i,'j':temp.j+1,'val':matrix[temp.i][temp.j+1]},'val');
        }
    }
    return res[k-1];
};
```

