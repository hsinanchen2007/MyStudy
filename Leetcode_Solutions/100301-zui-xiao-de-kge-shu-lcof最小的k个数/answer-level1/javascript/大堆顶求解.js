```
let getLeastNumbers = function(nums, k) {
  heapSort(nums, k)
  return nums.slice(0,k)
}
function heapSort(arr, k) {
  buildMaxHeap(arr, k)
  for(let i = arr.length - 1; i >= k; i--) {
    if(arr[0] >= arr[i]) {
      [arr[0], arr[i]] = [arr[i], arr[0]]
      heapify(arr, 0, k)
    }
  }
  return arr
}
function buildMaxHeap(arr, k) {
  let len = arr.length
  k = k > len ? len : k
  for(let i = k>>1 - 1; i >= 0; i--){
    heapify(arr, i, k)
  }
}
function heapify(arr, i, len) {
  let left = 2*i+1, right = 2*i+2, largest = i
  if(left < len && arr[left] > arr[largest]) {
    largest = left
  }
  if(right < len && arr[right] > arr[largest]) {
    largest = right
  }
  if(largest != i) {
    [arr[i], arr[largest]] = [arr[largest], arr[i]]
    heapify(arr, largest, len)
  }
}
```
