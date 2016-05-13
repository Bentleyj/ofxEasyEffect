#version 120

uniform sampler2DRect inputTexture;
uniform vec2 inputTextureSize;
uniform float pixel_w;
uniform float pixel_h;

void main() {
    
    vec2 uv = gl_TexCoord[0].xy;
    
    float dx = pixel_w;
    float dy = pixel_h;
    vec2 coord = vec2(dx*floor(uv.x/dx), dy*floor(uv.y/dy));
    vec3 tc = texture2DRect(inputTexture, coord).rgb;
    gl_FragColor = vec4(tc, 1.0);
}