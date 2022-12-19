```
class NestedIterator {
    vector<NestedInteger>::const_iterator currentPoint, endPoint;
    NestedIterator *it;
public:
    NestedIterator(const vector<NestedInteger> &nestedList) {
        this->currentPoint = nestedList.begin();
        this->endPoint = nestedList.end();
        it = NULL;
    }
    
    ~NestedIterator(){
        if(it!=NULL) delete it;
    }

    int next() {       
        if(currentPoint->isInteger()){
            return currentPoint++ ->getInteger(); 
        }
        else{
            return it->next();
        }
    }

    bool hasNext() {
        while(currentPoint!=endPoint){
            if(currentPoint->isInteger()) return true;
            else{
                if(it==NULL) it = new NestedIterator(currentPoint->getList());
                if(it->hasNext()){
                    return true;
                }else{
                    delete it;
                    it = NULL;
                }
            }
            
            currentPoint ++;
        }
        
        return false;
    }
};
```
