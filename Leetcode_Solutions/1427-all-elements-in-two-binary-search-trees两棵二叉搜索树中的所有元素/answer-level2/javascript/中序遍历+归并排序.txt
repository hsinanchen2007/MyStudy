```
var getAllElements = function(root1, root2) {
  function order(root, res) {
    let temp = [];
    while(root || temp.length) {
      while(root) {
        temp.push(root);
        root = root.left;
      }
      if (temp.length) {
        root = temp.pop();
        res.push(root.val)
        root = root.right;
      }
    }
  }
  function mergeSort(arr1, arr2) {
    let a1 = 0
    let a2 = 0
    let res = [];
    while (a1 < arr1.length && a2 < arr2.length) {
      if (arr1[a1] <= arr2[a2]) {
        res.push(arr1[a1++])
      } else {
        res.push(arr2[a2++])
      }
    }
    if (a1 === arr1.length) {
      return res.concat(...arr2.slice(a2))
    } else {
      return res.concat(...arr1.slice(a1))
    }
  }
  let arr1 = [];
  let arr2 = [];
  order(root1, arr1)
  order(root2, arr2)
  return mergeSort(arr1, arr2);
};
```
