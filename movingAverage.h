#include<array>
#include<string>

template<typename _Tp, std::size_t _Nm>
struct MovingAverage: public std::array<_Tp, _Nm>{
    template<typename T=float>
    T getAverage(){
        T sum = 0;
        for(const auto &it:*this){
            sum += it;
        }
        return sum / _Nm;
    }

    void push(_Tp value){
        this->data()[headIndex] = value;
        headIndex = (headIndex+1)%_Nm;
    }

private:
    uint8_t headIndex = 0;
};

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& o, MovingAverage<T,N>& obj){
	for(uint8_t n=0; n<N; n++){
        o << std::to_string(obj[n]);
        if(n<N-1){
            o << ", ";
        }
    }
	return o;
}