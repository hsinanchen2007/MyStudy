考试的时候感觉暴力能过，随手瞎写了一下，居然真的过了。

```
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        record.emplace_back(num);
    }
    
    int getProduct(int k) {
        int result = 1;
        for (int i = record.size() - k; i < record.size(); i++) {
            result*=record[i];
        }
        return result;
    }

private:
    vector<int> record;
};

```
