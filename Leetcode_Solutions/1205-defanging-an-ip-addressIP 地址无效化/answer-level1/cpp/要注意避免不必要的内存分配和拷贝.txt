不要用insert或者operator +，这些会涉及内存的分配和拷贝。应该一次性分配好所需空间，然后把数据拷贝过去。
注意如果循环里不是用指针而是用operator []的话开销会更大。

```
class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        result.resize( address.size() + 3 * 2 );
        auto* presult= result.data();
        for( const auto c : address ){
            if( c != '.' ){
                *(presult++)= c;
            }else{
                *(presult)= '[';
                *(presult+1)= '.';
                *(presult+2)= ']';
                presult += 3;
            }
        }
        return result;
    }
};
```
