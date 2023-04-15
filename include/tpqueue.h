// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
   char ch;
   int prior;
  public:
   char GetChar()const {
     return ch;
   }
   int GetPrior() const {
     return prior;
   }
};

template<typename T, const int size>
class TPQueue {
  private:
  T arr[size];
  int first, last, count/*, prioriti*/;
  void Transportation(int index, const SYM& value) {
  int temp = first;
  for (int i = last; i >= index; --i) {
    arr[i + 1] = arr[i];
  }
  first = temp;
  int in = index % size;
  arr[index] = value;
  last = (last + 1) % size;
  }

  int SearchInd(int prior) {
    if (arr[first].GetPrior() < prior) {
      return first;
    } else if (arr[last].GetPrior() >= prior) {
        return (last + 1) % size;
      } else {
          int pr = last;
          for (int i = last; i >first; --i) {
            if (arr[i].GetPrior() < prior) {
              pr = i;
              continue;
            } else
                break;
              }
              return pr;
            }
  }


public:
  TPQueue() : first(0), last(0), count(0) {};
  bool isEmpty()const {
    return count == 0;
  }
  bool isFull() const {
    return count == size;
  }
  void  push(const SYM& value) {
    if (isEmpty()) {
      arr[first] = value;
      ++count;
    } else {
        int index = SearchInd(value.GetPrior());
        Transportation(index, value);
        ++count;
      }
    }
  T pop() {
    T temp = arr[first];
    first = (first + 1)%size;
    --count;
    return temp;
  }
  int First()const {
    return first;
  }
  int Last()const {
    return last;
  }
};

#endif  // INCLUDE_TPQUEUE_H_
