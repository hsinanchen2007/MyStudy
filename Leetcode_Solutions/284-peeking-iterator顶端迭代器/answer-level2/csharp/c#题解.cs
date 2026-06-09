C#题解

```
// C# IEnumerator interface reference:
// https://docs.microsoft.com/en-us/dotnet/api/system.collections.ienumerator?view=netframework-4.8

class PeekingIterator {
    // iterators refers to the first element of the array.
    IEnumerator<int> iter;
    bool next=true;
    public PeekingIterator(IEnumerator<int> iterator) {
        // initialize any member here.
        iter=iterator;
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    public int Peek() {
        return iter.Current;
    }
    
    // Returns the next element in the iteration and advances the iterator.
    public int Next() {
        int a=iter.Current;
        next=iter.MoveNext();
        return a;
    }
    
    // Returns false if the iterator is refering to the end of the array of true otherwise.
    public bool HasNext() {
        if(next)return next;        
        return false;
    }
}
```
