不用记录前指针位置，只记录后指针位置即可
感觉实现比较简洁；

	class MyCircularQueue {
	public:
		/** Initialize your data structure here. Set the size of the queue to be k. */
		MyCircularQueue(int k) {
			_size = k;
			_cur_size = 0;
			_next = 0;
			_list = new int[k];
		}
		
		/** Insert an element into the circular queue. Return true if the operation is successful. */
		bool enQueue(int value) {
			if (_cur_size < _size){
				*(_list+_next) = value;
				++_next;
				_next %= _size;
				++_cur_size;
				return true;
			}
			return false;
		}
		
		/** Delete an element from the circular queue. Return true if the operation is successful. */
		bool deQueue() {
			if (_cur_size > 0){
				--_cur_size;
			}
			return true;
		}
		
		/** Get the front item from the queue. */
		int Front() {
			if (_cur_size == 0 || _size == 0){
				return -1;
			}
			
			return *(_list+(_next+_size-_cur_size)%_size);
		}
		
		/** Get the last item from the queue. */
		int Rear() {
			if (_cur_size == 0 || _size == 0){
				return -1;
			}
			
			return *(_list+(_next+_size-1)%_size);
		}
		
		/** Checks whether the circular queue is empty or not. */
		bool isEmpty() {
			return _cur_size == 0 && _size != 0;
		}
		
		/** Checks whether the circular queue is full or not. */
		bool isFull() {
			return _size == _cur_size;
		}
		
	private:
		int _size;
		int _cur_size;
		int* _list;
		int _next;
	};