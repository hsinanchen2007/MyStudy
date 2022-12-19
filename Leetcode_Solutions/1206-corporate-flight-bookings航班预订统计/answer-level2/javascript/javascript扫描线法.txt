
**解题思路：**

将每一段 `[i,j,ticket]` 想象成一个由 `i` 点往右边发出的 `ticket` 条射线，然后在 `j` 位置有一块挡板挡住了 `ticket` 条，那么 `[0,n]` 的每一个点有多少条射线即为所求，因此：  
1. 记录所有发出射线以及挡住射线的点，以及发出或者挡住的射线的数目
2. 由 `0` 点开始，依次往右扫描，每遇到一个那么通过它的射线的数目：`上一个点结束之后的数目 + 新发出的射线的数目`
3. 计算该点之后的射线数目：`通过改点的数目 - 被改点挡住的射线的数目`

时间复杂度为:$O(n)$

空间复杂度最大为:$O(2*n)$，需要使用两个 `Map` 来保存对应的索引的加票数以及减票数，当然也能够直接将加票数和减票数保存到同一个 `Map`

**代码1:**

```javascript 
var corpFlightBookings = function(bookings, n) {
    let segmentsArr = [];
    for(let i=0;i<bookings.length;i++){
        let [start,end,tickets]=bookings[i];
        segmentsArr.push([start,tickets])
        segmentsArr.push([end,-tickets])
    }
    segmentsArr.sort((a,b)=>a[0]==b[0]?b[1]-a[1]:a[0]-b[0]);
    
    let index=0;
    //当前位置对应的票数
    let sum=0;
    let ans=new Array(n);
    for(let i=0;i<n;i++){
        while(index<segmentsArr.length && segmentsArr[index][0]<=i+1 && segmentsArr[index][1]>=0){
            sum+=segmentsArr[index][1];
            index++;
        }
        ans[i]=sum;
        while(index<segmentsArr.length && segmentsArr[index][0]<=i+1 && segmentsArr[index][1]<0){
            sum+=segmentsArr[index][1];
            index++;
        }
    }
    return ans;
};
```
**代码2:**
```javascript 
//扫描线法，从左到右依次扫描
var corpFlightBookings = function(bookings, n) {
    let addMap = new Map();
    let minusMap = new Map();
    for(let i=0;i<bookings.length;i++){
        let [start,end,tickets]=bookings[i];
        addMap.set(start,(addMap.get(start)||0)+tickets);
        minusMap.set(end,(minusMap.get(end)||0)+tickets);
    }
    let sum=0;
    let ans=new Array(n);
    for(let i=0;i<n;i++){
        sum+=addMap.get(i+1)||0;
        ans[i]=sum;
        sum-=minusMap.get(i+1)||0;
    }
    return ans;
};
```
