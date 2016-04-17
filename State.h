//
// Created by Don Browne on 14/06/15.
//

#ifndef BF_STATE_H
#define BF_STATE_H

#include <memory>
#include <vector>

class State {
private:
    std::unique_ptr<std::vector<unsigned char> > tape;
    size_t index;
    size_t size;
public:
    State(size_t tape_length);
    ~State() {};

    void next();
    void prev();
    void assign(unsigned char val);
    unsigned char get();
    void incr();
    void decr();
};

#endif //BF_STATE_H
