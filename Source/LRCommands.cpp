/*
  ==============================================================================

    LRCommands.cpp
    Created: 31 Jul 2015 10:21:12pm
    Author:  Parth

  ==============================================================================
*/

#include <unordered_map>
#include "LRCommands.h"
#include "CommandMap.h"

const std::vector<String> LRCommandList::AdjustmentStringList = {
    "Temperature",
    "Tint",
    "Exposure",
    "Contrast",
    "Highlights",
    "Shadows",
    "Whites",
    "Blacks",
    "Clarity",
    "Vibrance",
    "Saturation",
    "Reset Temperature",
    "Reset Tint",
    "Reset Exposure",
    "Reset Contrast",
    "Reset Highlights",
    "Reset Shadows",
    "Reset Whites",
    "Reset Blacks",
    "Reset Clarity",
    "Reset Vibrance",
    "Reset Saturation",
};

const std::vector<String> LRCommandList::ToneStringList = {
    "Parametric Darks",
    "Parametric Lights",
    "Parametric Shadows",
    "Parametric Highlights",
    "Parametric Shadow Split",
    "Parametric Midtone Split",
    "Parametric Highlight Split",
    "Reset Parametric Darks",
    "Reset Parametric Lights",
    "Reset Parametric Shadows",
    "Reset Parametric Highlights",
    "Reset Parametric Shadow Split",
    "Reset Parametric Midtone Split",
    "Reset Parametric Highlight Split",

};

const std::vector<String> LRCommandList::MixerStringList = {
    // Colour
    "Saturation Adjustment Red",
    "Saturation Adjustment Orange",
    "Saturation Adjustment Yellow",
    "Saturation Adjustment Green",
    "Saturation Adjustment Aqua",
    "Saturation Adjustment Blue",
    "Saturation Adjustment Purple",
    "Saturation Adjustment Magenta",
    "Hue Adjustment Red",
    "Hue Adjustment Orange",
    "Hue Adjustment Yellow",
    "Hue Adjustment Green",
    "Hue Adjustment Aqua",
    "Hue Adjustment Blue",
    "Hue Adjustment Purple",
    "Hue Adjustment Magenta",
    "Luminance Adjustment Red",
    "Luminance Adjustment Orange",
    "Luminance Adjustment Yellow",
    "Luminance Adjustment Green",
    "Luminance Adjustment Aqua",
    "Luminance Adjustment Blue",
    "Luminance Adjustment Purple",
    "Luminance Adjustment Magenta",
    // B & W
    "Gray Mixer Red",
    "Gray Mixer Orange",
    "Gray Mixer Yellow",
    "Gray Mixer Green",
    "Gray Mixer Aqua",
    "Gray Mixer Blue",
    "Gray Mixer Purple",
    "Gray Mixer Magenta",
};

const std::vector<String> LRCommandList::SplitToningStringList = {
    "Split Toning Shadow Hue",
    "Split Toning Shadow Saturation",
    "Split Toning Highlight Hue",
    "Split Toning Highlight Saturation",
    "Split Toning Balance",
};

const std::vector<String> LRCommandList::DetailStringList = {
    "Sharpness",
    "Sharpen Radius",
    "Sharpen Detail",
    "Sharpen Edge Masking",
    "Luminance Smoothing",
    "Luminance Noise Reduction Detail",
    "Luminance Noise Reduction Contrast",
    "Color Noise Reduction",
    "Color Noise Reduction Detail",
    "Color Noise Reduction Smoothness",
    "Reset Sharpness",
    "Reset Sharpen Radius",
    "Reset Sharpen Detail",
    "Reset Sharpen Edge Masking",
    "Reset Luminance Smoothing",
    "Reset Luminance Noise Reduction Detail",
    "Reset Luminance Noise Reduction Contrast",
    "Reset Color Noise Reduction",
    "Reset Color Noise Reduction Detail",
    "Reset Color Noise Reduction Smoothness",
};

const std::vector<String> LRCommandList::LensCorrectionStringList = {
    "Lens Profile Distortion Scale",
    "Lens Profile Chromatic Aberration Scale",
    "Lens Profile Vignetting Scale",
    "Lens Manual Distortion Amount",
    "Defringe Purple Amount",
    "Defringe Purple Hue Lo",
    "Defringe Purple Hue Hi",
    "Defringe Green Amount",
    "Defringe Green Hue Lo",
    "Defringe Green Hue Hi",
    "Perspective Vertical",
    "Perspective Horizontal",
    "Perspective Rotate",
    "Perspective Scale",
    "Perspective Aspect",
    "Perspective Upright",
};

const std::vector<String> LRCommandList::EffectsStringList = {
    "Dehaze",
    "Post Crop Vignette Amount",
    "Post Crop Vignette Midpoint",
    "Post Crop Vignette Feather",
    "Post Crop Vignette Roundness",
    "Post Crop Vignette Style",
    "Post Crop Vignette Highlight Contrast",
    "Grain Amount",
    "Grain Size",
    "Grain Frequency",
    "Reset Dehaze",
};

const std::vector<String> LRCommandList::CalibrateStringList = {
    "Shadow Tint",
    "Red Hue",
    "Red Saturation",
    "Green Hue",
    "Green Saturation",
    "Blue Hue",
    "Blue Saturation"
};

const std::vector<String> LRCommandList::SelectionList = {
    "Pick",
    "Reject",
    "Next Photo",
    "Previous Photo",
    "Remove Flag",
    "Increase Rating",
    "Decrease Rating",
    "Set Rating To 0",
    "Set Rating To 1",
    "Set Rating To 2",
    "Set Rating To 3",
    "Set Rating To 4",
    "Set Rating To 5",
    "Toggle Blue Label",
    "Toggle Green Label",
    "Toggle Red Label",
    "Toggle Purple Label",
    "Toggle Yellow Label",
    "Reset All Develop Adjustments",
    "Reset Last Develop Parameter",
    "Undo",
    "Redo",
};

const std::vector<String> LRCommandList::ToolsList = {
    "Loupe",
    "Crop Overlay",
    "Spot Removal",
    "Red Eye",
    "Graduated Filter",
    "Radial Filter",
    "Adjustment Brush",
};

const std::vector<String> LRCommandList::LRStringList = {
    "Unmapped",
    /* Adjust */
    "Temperature",
    "Tint",
    "Exposure",
    "Contrast",
    "Highlights",
    "Shadows",
    "Whites",
    "Blacks",
    "Clarity",
    "Vibrance",
    "Saturation",
    "ResetTemperature",
    "ResetTint",
    "ResetExposure",
    "ResetContrast",
    "ResetHighlights",
    "ResetShadows",
    "ResetWhites",
    "ResetBlacks",
    "ResetClarity",
    "ResetVibrance",
    "ResetSaturation",

    /* Tone*/
    "ParametricDarks",
    "ParametricLights",
    "ParametricShadows",
    "ParametricHighlights",
    "ParametricShadowSplit",
    "ParametricMidtoneSplit",
    "ParametricHighlightSplit",
    "ResetParametricDarks",
    "ResetParametricLights",
    "ResetParametricShadows",
    "ResetParametricHighlights",
    "ResetParametricShadowSplit",
    "ResetParametricMidtoneSplit",
    "ResetParametricHighlightSplit",

    /* Mixer */
    "SaturationAdjustmentRed",
    "SaturationAdjustmentOrange",
    "SaturationAdjustmentYellow",
    "SaturationAdjustmentGreen",
    "SaturationAdjustmentAqua",
    "SaturationAdjustmentBlue",
    "SaturationAdjustmentPurple",
    "SaturationAdjustmentMagenta",
    "HueAdjustmentRed",
    "HueAdjustmentOrange",
    "HueAdjustmentYellow",
    "HueAdjustmentGreen",
    "HueAdjustmentAqua",
    "HueAdjustmentBlue",
    "HueAdjustmentPurple",
    "HueAdjustmentMagenta",
    "LuminanceAdjustmentRed",
    "LuminanceAdjustmentOrange",
    "LuminanceAdjustmentYellow",
    "LuminanceAdjustmentGreen",
    "LuminanceAdjustmentAqua",
    "LuminanceAdjustmentBlue",
    "LuminanceAdjustmentPurple",
    "LuminanceAdjustmentMagenta",
    "GrayMixerRed",
    "GrayMixerOrange",
    "GrayMixerYellow",
    "GrayMixerGreen",
    "GrayMixerAqua",
    "GrayMixerBlue",
    "GrayMixerPurple",
    "GrayMixerMagenta",
    /* Split Toning */
    "SplitToningShadowHue",
    "SplitToningShadowSaturation",
    "SplitToningHighlightHue",
    "SplitToningHighlightSaturation",
    "SplitToningBalance",
    /* Detail */
    "Sharpness",
    "SharpenRadius",
    "SharpenDetail",
    "SharpenEdgeMasking",
    "LuminanceSmoothing",
    "LuminanceNoiseReductionDetail",
    "LuminanceNoiseReductionContrast",
    "ColorNoiseReduction",
    "ColorNoiseReductionDetail",
    "ColorNoiseReductionSmoothness",
    "ResetSharpness",
    "ResetSharpenRadius",
    "ResetSharpenDetail",
    "ResetSharpenEdgeMasking",
    "ResetLuminanceSmoothing",
    "ResetLuminanceNoiseReductionDetail",
    "ResetLuminanceNoiseReductionContrast",
    "ResetColorNoiseReduction",
    "ResetColorNoiseReductionDetail",
    "ResetColorNoiseReductionSmoothness",
    /* Lens Correction */
    "LensProfileDistortionScale",
    "LensProfileChromaticAberrationScale",
    "LensProfileVignettingScale",
    "LensManualDistortionAmount",
    "DefringePurpleAmount",
    "DefringePurpleHueLo",
    "DefringePurpleHueHi",
    "DefringeGreenAmount",
    "DefringeGreenHueLo",
    "DefringeGreenHueHi",
    "PerspectiveVertical",
    "PerspectiveHorizontal",
    "PerspectiveRotate",
    "PerspectiveScale",
    "PerspectiveAspect",
    "PerspectiveUpright",
    /* Effects */
    "Dehaze",
    "PostCropVignetteAmount",
    "PostCropVignetteMidpoint",
    "PostCropVignetteFeather",
    "PostCropVignetteRoundness",
    "PostCropVignetteStyle",
    "PostCropVignetteHighlightContrast",
    "GrainAmount",
    "GrainSize",
    "GrainFrequency",
    "ResetDehaze",
    /* Calibrate */
    "ShadowTint",
    "RedHue",
    "RedSaturation",
    "GreenHue",
    "GreenSaturation",
    "BlueHue",
    "BlueSaturation",
    /* Selection Actions */
    "Pick",
    "Reject",
    "Next",
    "Prev",
    "RemoveFlag",
    "IncreaseRating",
    "DecreaseRating",
    "SetRating0",
    "SetRating1",
    "SetRating2",
    "SetRating3",
    "SetRating4",
    "SetRating5",
    "ToggleBlue",
    "ToggleGreen",
    "ToggleRed",
    "TogglePurple",
    "ToggleYellow",
    "ResetAll",
    "ResetLast",
    "Undo",
    "Redo",
    /* Tools */
    "Loupe",
    "CropOverlay",
    "SpotRemoval",
    "RedEye",
    "GraduatedFilter",
    "RadialFilter",
    "AdjustmentBrush",
};

const std::vector<String> LRCommandList::ProfileList = {
  "Previous Profile",
  "Next Profile",
};

int LRCommandList::getIndexOfCommand(const String& command)
{
    static std::unordered_map<String, int> indexMap;
    if (indexMap.size() == 0)
    {
        int idx = 0;
        for (auto &str : LRStringList)
            indexMap[str] = idx++;

        for (auto &str : ProfileList)
            indexMap[str] = idx++;
    }

    return indexMap[command];

}