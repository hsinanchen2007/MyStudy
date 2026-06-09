```cpp
string toGoatLatin(string S) {
    unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
    int anchor = 0, k = 1;
    for (int cur = 0; cur <= S.length(); cur++) {
        if (cur != S.length() && isalpha(S[cur])) continue;
        if (!vowels.count(tolower(S[anchor]))) {
            S.insert(cur, 1, S[anchor]);
            S.erase(S.begin() + anchor);
        }
        S.insert(cur, "ma");
        S.insert(cur + 2, k, 'a');
        cur += 2 + k++;
        anchor = cur + 1;
    }
    return S;
}
```