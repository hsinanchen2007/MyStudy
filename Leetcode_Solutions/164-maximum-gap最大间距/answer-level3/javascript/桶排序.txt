

   
### 选择算法，尝试过计数排序，选择桶排序

#### 牺牲空间获取时间

```bash
执行结果：通过
执行用时 :100 ms, 在所有 JavaScript 提交中击败了98.39% 的用户
内存消耗 :41.2 MB, 在所有 JavaScript 提交中击败了5.48%的用户
```

```bash

function bucketSort(arr,bucketNum){
  if(arr.length === 0){
    return arr
  }
  //1.找出最大最小值
  let i =0, min = arr[0],max = arr[0]
  for (let i =0;i<arr.length;i++){
    if(arr[i]>max) max = arr[i]
    if(arr[i]<min) min = arr[i]
  }
  //2.桶的初始化

  bucketNum = bucketNum || 5  //桶的个数
  let bucketSize = ~~((max-min+1)/bucketNum) //桶的大小
  let buckets = new Array(bucketNum*2) 
  for (i=0;i<buckets.length;i++){
    buckets[i] = [] //初始化桶
  }
  //3.分配数据到桶，这里直接按照数据值的分布来分配,一定范围内均匀分布的数据效率最为高效~~((arr[i]-min)/bucketSize)
  for (i=0;i<arr.length;i++){
    buckets[~~((arr[i]-min)/bucketSize)].push(arr[i])
  }

  //4.对每个桶进行排序，并输出数据
  let sortedArr = []
  for (i=0;i<buckets.length;i++){
    buckets[i].sort((a,b)=>a-b) //对每个桶进行排序
    for (let j =0;j<buckets[i].length;j++){
      sortedArr.push(buckets[i][j])
    }
  }
  return sortedArr
}

var maximumGap = function(nums) {
   let max =0
  let sortedArr = bucketSort(nums,~~(nums.length/2))
  for(let i=0;i<sortedArr.length-1;i++){
    let sub = sortedArr[i+1]-sortedArr[i]
    if(sub>max){max = sub}
  }
  return max
};
```

