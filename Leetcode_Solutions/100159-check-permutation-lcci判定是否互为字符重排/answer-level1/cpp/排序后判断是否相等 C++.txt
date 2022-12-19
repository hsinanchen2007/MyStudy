    //C++
    //排序后判断是否相等
    bool CheckPermutation(string s1, string s2) {
      sort(s1.begin(),s1.end());
      sort(s2.begin(),s2.end());
      return (s1 == s2 ? true : false);
      
    }