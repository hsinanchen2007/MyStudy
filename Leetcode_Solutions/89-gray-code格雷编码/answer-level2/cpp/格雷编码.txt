```cpp
   void grayCodeHelper(vector<int> &ret, unsigned int *now, unsigned int n) {
    if (n == 1) {
        *now = *now ^ 1;
        ret.push_back(*now);
        return;
    }
    grayCodeHelper(ret, now, n >> 1);
    *now = *now ^ n;
    ret.push_back(*now);
    grayCodeHelper(ret, now, n >> 1);

}

vector<int> grayCode(int n) {

    unsigned int now = 0;
    vector<int> ret{0};
    if (n > 0) grayCodeHelper(ret, &now, 1 << n -1);
    return ret;
}
```