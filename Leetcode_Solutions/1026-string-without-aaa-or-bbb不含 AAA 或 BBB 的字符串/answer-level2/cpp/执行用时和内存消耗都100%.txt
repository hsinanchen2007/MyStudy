```c++
string strWithout3a3b(int A, int B) {
    char a = 'a', b = 'b';
    if (A < B) {
        swap(a, b);
        swap(A, B);
    }
    string res;
    // "aabb"
    while(2*B >= A && A >= 2 && B >= 2) {
        res.push_back(a); res.push_back(a);
        res.push_back(b); res.push_back(b);
        A-=2; B-=2;
    }
    // "aab"
    while(A >= 2 && B > 0) {
        res.push_back(a); res.push_back(a);
        res.push_back(b);
        A-=2; B--;
    }
    // "a"
    while(A--) {
        res.push_back(a);
    }
    // "b"
    while(B--) {
        res.push_back(b);
    }
    return res;
}
```

首先假设 A >= B，如果不符合，则通过 swap 构造出成符合的情况。然后分情况讨论：

1. 当`2*B >= A`时，总是 append "aabb"
2. 当`2*B > A`时，总是 append "aab"
3. 其余情况， append "a" 或 "b" 即可
