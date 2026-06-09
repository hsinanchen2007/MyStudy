### 解题思路


### 思路1

把nums2拷贝到nums1的尾部，然后对nums1重排序

时间复杂度O(NlogN)(内部使用快排or归排)

空间复杂度O(1)，没有额外空间

缺点，没有利用到两个数组有序的特点

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i = m; i < m + n; i++) {
        nums1[i] = nums2[i-m];
    }
    sort(nums1.begin(), nums1.end());
}
```

### 思路2

从左到右放置元素，先小后大

为了不移动nums1元素，使用一个tmp元素保存nums1的前m个元素。

利用3个指针，p指向tmp1第一个元素，q指向nums2第一个元素， i指向nums1的第一个元素。依次比较p、q指向的两个元素大小，小的放到i指向的位置


时间复杂度O(n+m)， 总共需要比遍历n+m此

空间复杂度O(m)， 需要存储m个元素

缺点， 使用了临时存储

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = 0;//指向tmp当前考虑的值
    int q = 0;//指向nums2当前考虑的值
    vector<int> tmp(nums1.begin(), nums1.begin() + m);//临时存储，避免后移，空间换时间
    int i = 0;//指向nums1当前待放置的元素
    while(p < m && q < n) {//依次比较
        nums1[i++] = tmp[p] < nums2[q] ? tmp[p++] : nums2[q++];//小的放到i指向的位置
    }
    while(p < m) {//p还没到头
        nums1[i++] = tmp[p++];
    }
    while(q < n) {//q还没到头
        nums1[i++] = nums2[q++];
    } 
}
```

### 思路3

上面从左到右那种方法使用tmp存储nums1的前m个元素，导致空间复杂度O(M)。

反过来从尾到头就可以避免浪费空间，因为nums1的尾部元素可以覆盖。

还是使用三个指针，i指向nums1的第m-1个元素， 也就是最后一个有效元素，

j指向nums2的尾部元素， k指向nums1最尾部元素，也就是最终最大值存放的位置。

i, j依次递减，比较指向的两个元素大小，大的放到k指向的位置，k递减。
```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;//i指向nums1的第m-1个元素
    int j = n - 1;//j指向nums2的尾部元素
    int k = m + n - 1;//k指向nums1最尾部元素

    while(i >= 0 && j >= 0) {//i, j依次递减，比较指向的两个元素大小，大的放到k指向的位置，k递减
        nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }

    while(i>=0)//nums1还没取完
        nums1[k--] = nums1[i--];
    while(j >= 0)//nums2还没取完
        nums1[k--] = nums2[j--];

}
```

