### 解题思路
![截屏2020-04-05 下午6.45.31.png](https://pic.leetcode-cn.com/c862300578709e1a69e259c656e8c2d956db80cb39435f78229845565857d638-%E6%88%AA%E5%B1%8F2020-04-05%20%E4%B8%8B%E5%8D%886.45.31.png)
###### 声明两个数组arr和count
- arr的索引为push进来的数据，索引对应的元素表示push/pop操作后，当前索引表示数组的个数
- count为二维数组，与arr作用相反，每一维数据对应当前存在维数的个数的数据集合，即count[[],[1,2,3],[1,2],[1]]表示，1有三个，2有两个，3有一个，每一次push根据存入数据根据其当前个数存入高一维中，即push（2），count变为[[],[1,2,3],[1,2],[1,2]]，push(3),count变为[1,2,3],[1,2，3],[1,2]]，每一次pop操作只需取出count的最后一维的最后一个数据，更新count即可。
- 可以看出，count低维数据对高维数据一定存在包含关系，不必担心连续pop操作后低一维是否为空。每一次push/pop保证了包含关系的单调性和连续性。
- 当某一维数据pop为空后，及时删除该维

### 代码

```javascript
var FreqStack = function () {
  this.arr = [];
  this.count = [];
};


FreqStack.prototype.push = function (x) {
  if (this.arr[x]) {
    this.arr[x]++;
  } else {
    this.arr[x] = 1;
  }
  if (this.count[this.arr[x]]) {
    this.count[this.arr[x]].push(x)
  } else {
    this.count[this.arr[x]] = [x]
  }
};

FreqStack.prototype.pop = function () {
  let row = this.count.length;
  let res = 0;
  if (this.count[row - 1].length === 0) {
    this.count.pop()
    res = this.count[row - 2].pop()
  } else {
    res = this.count[row - 1].pop();
  }
  this.arr[res]--;
  return res
};


```