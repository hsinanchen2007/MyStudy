用一个双向链表维护一组有序的container，每个container用map储存着值相同的key，然后一个map储存每个Key所在的container，最大最小就从头尾的container中取key就行了

```
/**
 * Initialize your data structure here.
 */
function Container(key, value=1){
    this.pre = null;
    this.next = null;
    this.value = value;
    this.keyMap = {[key]:true};
    this.length = 1;
}
Container.prototype.add = function(key){
    this.length += 1;
    this.keyMap[key] = true;
}
Container.prototype.delete = function(key){
    if(this.keyMap[key]){
        this.length -= 1;
        delete this.keyMap[key];
    }
}
Container.prototype.destroy = function(){
    if(this.pre && this.next){
        this.pre.next = this.next;
        this.next.pre = this.pre;
    }else if(this.pre){
        this.pre.next = null;
    }else if(this.next){
        this.next.pre = null;
    }
}

Container.prototype.inc = function(key){
    if(this.keyMap[key]){
        if(this.next && this.next.value === this.value + 1){
            this.next.add(key);
            this.delete(key);
            return {isEmpty: this.length === 0}
        }else{
            const next = new Container(key, this.value + 1);
            next.next = this.next;
            next.pre = this;
            this.next = next;
            next.next && (next.next.pre = next);
            this.delete(key);
            return {isEmpty: this.length === 0}
        }
    }
}

Container.prototype.dec = function(key){
    if(this.keyMap[key]){
        if(this.value === 1){
            this.delete(key);
            return {isEmpty: this.length === 0};
        }else if(this.pre && this.pre.value === this.value - 1){
            this.pre.add(key);
            this.delete(key);
            return {isEmpty: this.length === 0}
        }else{
            const pre = new Container(key, this.value - 1);
            pre.next = this;
            pre.pre = this.pre;
            this.pre = pre;
            pre.pre && (pre.pre.next = pre);
            this.delete(key);
            return {isEmpty: this.length === 0}
        }
    }
}
var AllOne = function() {
    this._map = {};
    this._head = null;
    this._tail = null;
};

/**
 * Inserts a new key <Key> with value 1. Or increments an existing key by 1. 
 * @param {string} key
 * @return {void}
 */
AllOne.prototype.inc = function(key) {
    if(this._map[key] === undefined){
        if(this._head && this._head.value === 1){
            this._head.add(key);
            this._map[key] = this._head;
        }else{
            const head = new Container(key);
            this._map[key] = head;
            if(this._head){
                this._head.pre = head;
            }else{
                this._tail = head;
            }
            head.next = this._head;
            this._head = head;
        }
    }else{
        const currentContainer = this._map[key];
        const res = currentContainer.inc(key);
        this._map[key] = currentContainer.next;
        if(currentContainer === this._tail){
            this._tail = currentContainer.next;
        }
        if(res.isEmpty && this._head === currentContainer){
            this._head = currentContainer.next;
        }
        if(res.isEmpty){
            currentContainer.destroy();
        }
    }
};

/**
 * Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. 
 * @param {string} key
 * @return {void}
 */
AllOne.prototype.dec = function(key) {
    if(this._map[key]){
        const currentContainer = this._map[key];
        const res = currentContainer.dec(key);
        if(currentContainer.value === 1){
            this._map[key] = undefined;
        }else{
            this._map[key] = currentContainer.pre;
        }
        if(currentContainer === this._head ){
            if(currentContainer.value === 1){
                if(res.isEmpty){
                    this._head = currentContainer.next? currentContainer.next : null;
                }
            }else{
                this._head = currentContainer.pre;
            }
        }
        if(res.isEmpty && this._tail === currentContainer){
            this._tail = currentContainer.pre;
        }
        if(res.isEmpty){
            currentContainer.destroy();
        }
    }
};

/**
 * Returns one of the keys with maximal value.
 * @return {string}
 */
AllOne.prototype.getMaxKey = function() {
    if(this._tail){
        for(let key in this._tail.keyMap){
            return key
        }
    }else{
        return ''
    }
};

/**
 * Returns one of the keys with Minimal value.
 * @return {string}
 */
AllOne.prototype.getMinKey = function() {
    if(this._head){
        for(let key in this._head.keyMap){
            return key
        }
    }else{
        return ''
    }
};


```
