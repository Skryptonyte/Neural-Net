#include <stdio.h>
#include <math.h>

struct neuron{
double data;
double* weights;

struct neuron *nextlayer;
struct neuron *bias;
};

double sigmoid(double x){
return (1/(exp(-x) + 1));
}

void connectlayers(struct neuron* layer, struct neuron* nextlayer, double* weights,int size, int size2){
for (int i = 0; i < size; i++){
layer[i].nextlayer = nextlayer;
layer[i].weights = weights+(i*size2);
//printf("%lf\n",*((weights+(i*size2))+1));
}
}

void forwardPropagate(struct neuron* firstlayer, struct neuron* secondlayer, int size, int size2){
for (int i = 0; i < size2; i++){
secondlayer[i].data = 0;
for (int j = 0; j < size; j++){
//printf("Weight: %lf\n",firstlayer[j].weights[i]);
secondlayer[i].data += firstlayer[j].data * firstlayer[j].weights[i];
}
secondlayer[i].data = sigmoid(secondlayer[i].data);
}
}

void backPropagate(){

}
int main(){
//Create layers
struct neuron inputs[2];
inputs[0].data = 2;
inputs[1].data = 1;
double weights[2][3] = {{0.5,0.6,0.7},{0.9,0.5,0.1}};

struct neuron firstlayer[3];
double weights2[3][2] = {{0.1,0.9},{0.1,0.8},{0.8,0.6}};

struct neuron lastlayer[2];

//Link the neural net
connectlayers(inputs, firstlayer, weights, 2, 3);
connectlayers(firstlayer, lastlayer, weights2 ,3, 2);

//Perform Forward Propagation
forwardPropagate(inputs, firstlayer,2,3);
forwardPropagate(firstlayer,lastlayer,3,2);

//printf("Sigmoid Test: %lf\n",sigmoid(1.9));
printf("Input: %lf %lf\n",inputs[0].data,inputs[1].data);
printf("First Layer: %lf %lf %lf\n",firstlayer[0].data, firstlayer[1].data, firstlayer[2].data);
printf("Output: %lf %lf\n",lastlayer[0].data, lastlayer[1].data);
}
