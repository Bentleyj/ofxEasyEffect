# ofxEasyEffect
An Easy Shader Manager with Gui controls for openframeworks. You have to write your own shaders but that's lik 99% of the fun anyway so yay!

# Usage
See example

This is basically just a class that lets you wrap 2D shaders in an easy way! Gives you ofxGui control of all your float uniforms and also allows you to add array and texture uniforms.

In setup load the shader using loadShader() and setup the gui using setupGui() then add any that you want to pass to the shader.

Once you've set it up all you need to do is have two framebuffer objects and use effect.apply(inBuffer, outBuffer); int he draw function which will let you easily apply the effects!

use effect.drawGui() to draw the gui which is controllable.

Have fun!

# Installation
Clone this repository into your addons folder.
The only dependency is ofxGui which comes standard with oF


